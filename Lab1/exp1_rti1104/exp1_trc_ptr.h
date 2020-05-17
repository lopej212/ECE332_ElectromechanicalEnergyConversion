/*********************** dSPACE target specific file *************************

   Header file exp1_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Jan 31 13:11:58 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_exp1_trc_ptr_h_
#define RTI_HEADER_exp1_trc_ptr_h_

/* Include the model header file. */
#include "exp1.h"
#include "exp1_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_exp1_real_T_0;
EXTERN_C volatile real_T *p_1_exp1_real_T_0;
EXTERN_C volatile int_T *p_2_exp1_int_T_2;
EXTERN_C volatile boolean_T *p_2_exp1_boolean_T_3;
EXTERN_C volatile real_T *p_3_exp1_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void exp1_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_exp1_trc_ptr_h_ */
