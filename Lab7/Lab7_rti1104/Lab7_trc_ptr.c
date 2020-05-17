/***************************************************************************

   Source file Lab7_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Mar 13 12:37:27 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Lab7_trc_ptr.h"
#include "Lab7.h"
#include "Lab7_private.h"

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
volatile real_T *p_0_Lab7_real_T_0 = NULL;
volatile int8_T *p_0_Lab7_int8_T_1 = NULL;
volatile boolean_T *p_0_Lab7_boolean_T_2 = NULL;
volatile real_T *p_1_Lab7_real_T_0 = NULL;
volatile real_T *p_2_Lab7_real_T_2 = NULL;
volatile int_T *p_2_Lab7_int_T_3 = NULL;
volatile boolean_T *p_2_Lab7_boolean_T_4 = NULL;
volatile real_T *p_3_Lab7_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Lab7_real_T_0 = &Lab7_B.SFunction2;
  p_0_Lab7_int8_T_1 = &Lab7_B.DataTypeConv1;
  p_0_Lab7_boolean_T_2 = &Lab7_B.NotEqual;
  p_1_Lab7_real_T_0 = &Lab7_P.DiscretePIDController1_D;
  p_2_Lab7_real_T_2 = &Lab7_DW.Integrator_DSTATE;
  p_2_Lab7_int_T_3 = &Lab7_DW.SFunction1_IWORK;
  p_2_Lab7_boolean_T_4 = &Lab7_DW.objisempty;
  p_3_Lab7_real_T_0 = &Lab7_Y.avg_rpm;
}

void Lab7_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
