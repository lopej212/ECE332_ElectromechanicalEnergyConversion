/***************************************************************************

   Source file Lab6_OpenLoop_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Mar  6 12:55:20 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Lab6_OpenLoop_trc_ptr.h"
#include "Lab6_OpenLoop.h"
#include "Lab6_OpenLoop_private.h"

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
volatile real_T *p_0_Lab6_OpenLoop_real_T_0 = NULL;
volatile real_T *p_0_Lab6_OpenLoop_real_T_1 = NULL;
volatile real_T *p_0_Lab6_OpenLoop_real_T_2 = NULL;
volatile real_T *p_0_Lab6_OpenLoop_real_T_3 = NULL;
volatile real_T *p_1_Lab6_OpenLoop_real_T_0 = NULL;
volatile int_T *p_2_Lab6_OpenLoop_int_T_0 = NULL;
volatile real_T *p_3_Lab6_OpenLoop_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Lab6_OpenLoop_real_T_0 = &Lab6_OpenLoop_B.Integrator;
  p_0_Lab6_OpenLoop_real_T_1 = &Lab6_OpenLoop_B.sf_MATLABFunction2.y;
  p_0_Lab6_OpenLoop_real_T_2 = &Lab6_OpenLoop_B.sf_MATLABFunction1.y;
  p_0_Lab6_OpenLoop_real_T_3 = &Lab6_OpenLoop_B.sf_MATLABFunction.y;
  p_1_Lab6_OpenLoop_real_T_0 = &Lab6_OpenLoop_P.Integrator_IC;
  p_2_Lab6_OpenLoop_int_T_0 = &Lab6_OpenLoop_DW.SFunction1_IWORK;
  p_3_Lab6_OpenLoop_real_T_0 = &Lab6_OpenLoop_X.Integrator_CSTATE;
}

void Lab6_OpenLoop_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
