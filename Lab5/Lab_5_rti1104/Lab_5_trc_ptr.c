/***************************************************************************

   Source file Lab_5_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Feb 28 13:40:01 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Lab_5_trc_ptr.h"
#include "Lab_5.h"
#include "Lab_5_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_Lab_5_real_T_0 = NULL;
volatile real_T *p_0_Lab_5_real_T_1 = NULL;
volatile real_T *p_0_Lab_5_real_T_2 = NULL;
volatile real_T *p_0_Lab_5_real_T_3 = NULL;
volatile real_T *p_1_Lab_5_real_T_0 = NULL;
volatile uint32_T *p_1_Lab_5_uint32_T_1 = NULL;
volatile real_T *p_2_Lab_5_real_T_2 = NULL;
volatile int_T *p_2_Lab_5_int_T_3 = NULL;
volatile boolean_T *p_2_Lab_5_boolean_T_4 = NULL;
volatile real_T *p_3_Lab_5_real_T_0 = NULL;
volatile real_T *p_5_Lab_5_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Lab_5_real_T_0 = &Lab_5_B.SFunction2;
  p_0_Lab_5_real_T_1 = &Lab_5_B.sf_MATLABFunction2.y;
  p_0_Lab_5_real_T_2 = &Lab_5_B.sf_MATLABFunction1.y;
  p_0_Lab_5_real_T_3 = &Lab_5_B.sf_MATLABFunction_j.y;
  p_1_Lab_5_real_T_0 = &Lab_5_P.velocity_Gain;
  p_1_Lab_5_uint32_T_1 = &Lab_5_P.Delay_DelayLength;
  p_2_Lab_5_real_T_2 = &Lab_5_DW.Delay_DSTATE;
  p_2_Lab_5_int_T_3 = &Lab_5_DW.SFunction1_IWORK;
  p_2_Lab_5_boolean_T_4 = &Lab_5_DW.objisempty;
  p_3_Lab_5_real_T_0 = &Lab_5_X.Integrator_CSTATE;
  p_5_Lab_5_real_T_0 = &Lab_5_Y.Out1;
}

void Lab_5_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
