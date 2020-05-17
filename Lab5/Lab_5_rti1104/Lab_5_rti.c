/*********************** dSPACE target specific file *************************

   Include file Lab_5_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1104 7.9 (02-Nov-2017)
   Fri Feb 28 13:40:01 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "Lab_5.h"
#include "Lab_5_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             Lab_5_B
#define RTP_STRUCTURE_NAME             Lab_5_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1104.h>
#include <slvdsp1104.h>
#include <rti_slv1104.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   2
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* flag = UNDEF */
int slaveDSPPwm3StopFlag = 2;

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.0001;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1104, (void *) 0,
                        VCM_TXT_RTI1104, 7, 9, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 3, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS1104SLAVE #1 */
  /* Initialize master - slave DSP communication */
  ds1104_slave_dsp_communication_init();

  /* Initialize automatic index generation */
  rti_slv1104_init_fcn_index();

  /* Initialize slave DSP error level */
  rti_slv1104_error_level = 0;

  /* dSPACE I/O Board DS1104SLAVE #1 Unit:PWM3_SV_INT */
  /* Register Slave DSP PWM3 */
  ds1104_slave_dsp_pwm3_duty_write_register(0, &rti_slv1104_fcn_index[0]);

  /* Initialize PWM3 */
  ds1104_slave_dsp_pwm3_init(0, 1.0 / 20000, 0.5, 0.5, 0.5, 1.0E-6,
    SLVDSP1104_PWM3_SYNC_OFF);
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);

  /* dSPACE I/O Board DS1104 #1 Unit:ENC_SETUP */
  ds1104_inc_init(1, DS1104_INC_MODE_TTL);
  ds1104_inc_init(2, DS1104_INC_MODE_TTL);

  /* Initialization of Master EncSetup units  */
  ds1104_inc_trigger_setup(1,DS1104_TRIGGER_DISABLE);
  ds1104_inc_trigger_setup(2,DS1104_TRIGGER_DISABLE);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1104 #1 Unit:ENC_POS */
  ds1104_inc_position_write(1, 0, DS1104_INC_LINE_SUBDIV_4);

  /* dSPACE I/O Board DS1104SLAVE #1 Unit:PWM3_SV_INT */
  rti_slv1104_taskqueue_error[0] = ds1104_slave_dsp_pwm3_duty_write(0,
    rti_slv1104_fcn_index[0], 0.5, 0.5, 0.5);
  rti_slv1104_taskqueue_error_check(0);
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);

  /* flag = UNDEF */
  slaveDSPPwm3StopFlag = 2;
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* dSPACE I/O Board DS1104SLAVE #1 */
  /* Check master - slave dsp communication */
  rti_slv1104_taskqueue_error_all_check();
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.0001, 0] */
  /* dSPACE I/O Board DS1104 #1 Unit:ENC_POS Group:POS */
  Lab_5_B.SFunction1 = (real_T) ds1104_inc_position_read(1,
    DS1104_INC_LINE_SUBDIV_4);

  /* dSPACE I/O Board DS1104 #1 Unit:ENC_POS Group:DPOS */
  Lab_5_B.SFunction2 = (real_T) ds1104_inc_delta_position_read(1,
    DS1104_INC_LINE_SUBDIV_4);
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
