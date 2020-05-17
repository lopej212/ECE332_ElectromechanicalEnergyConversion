/*********************** dSPACE target specific file *************************

   Header file Lab_4_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Feb 21 12:40:46 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Lab_4_trc_ptr_h_
#define RTI_HEADER_Lab_4_trc_ptr_h_

/* Include the model header file. */
#include "Lab_4.h"
#include "Lab_4_private.h"
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
EXTERN_C volatile real_T *p_0_Lab_4_real_T_0;
EXTERN_C volatile real_T *p_1_Lab_4_real_T_0;
EXTERN_C volatile int_T *p_2_Lab_4_int_T_2;
EXTERN_C volatile boolean_T *p_2_Lab_4_boolean_T_3;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Lab_4_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_Lab_4_trc_ptr_h_ */
