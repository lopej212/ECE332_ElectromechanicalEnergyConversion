/***************************************************************************

   Source file Lab_4_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Feb 21 13:41:25 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Lab_4_trc_ptr.h"
#include "Lab_4.h"
#include "Lab_4_private.h"

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
volatile real_T *p_0_Lab_4_real_T_0 = NULL;
volatile real_T *p_0_Lab_4_real_T_1 = NULL;
volatile real_T *p_0_Lab_4_real_T_2 = NULL;
volatile real_T *p_0_Lab_4_real_T_3 = NULL;
volatile real_T *p_1_Lab_4_real_T_0 = NULL;
volatile int_T *p_2_Lab_4_int_T_2 = NULL;
volatile boolean_T *p_2_Lab_4_boolean_T_3 = NULL;
volatile real_T *p_3_Lab_4_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Lab_4_real_T_0 = &Lab_4_B.SFunction1;
  p_0_Lab_4_real_T_1 = &Lab_4_B.sf_MATLABFunction2.y;
  p_0_Lab_4_real_T_2 = &Lab_4_B.sf_MATLABFunction1.y;
  p_0_Lab_4_real_T_3 = &Lab_4_B.sf_MATLABFunction.y;
  p_1_Lab_4_real_T_0 = &Lab_4_P.velocity_Gain;
  p_2_Lab_4_int_T_2 = &Lab_4_DW.SFunction1_IWORK;
  p_2_Lab_4_boolean_T_3 = &Lab_4_DW.objisempty;
  p_3_Lab_4_real_T_0 = &Lab_4_X.Integrator_CSTATE;
}

void Lab_4_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
