/*********************** dSPACE target specific file *************************

   Header file Lab_5_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Feb 28 13:40:01 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Lab_5_trc_ptr_h_
#define RTI_HEADER_Lab_5_trc_ptr_h_

/* Include the model header file. */
#include "Lab_5.h"
#include "Lab_5_private.h"
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
EXTERN_C volatile real_T *p_0_Lab_5_real_T_0;
EXTERN_C volatile real_T *p_0_Lab_5_real_T_1;
EXTERN_C volatile real_T *p_0_Lab_5_real_T_2;
EXTERN_C volatile real_T *p_0_Lab_5_real_T_3;
EXTERN_C volatile real_T *p_1_Lab_5_real_T_0;
EXTERN_C volatile uint32_T *p_1_Lab_5_uint32_T_1;
EXTERN_C volatile real_T *p_2_Lab_5_real_T_2;
EXTERN_C volatile int_T *p_2_Lab_5_int_T_3;
EXTERN_C volatile boolean_T *p_2_Lab_5_boolean_T_4;
EXTERN_C volatile real_T *p_3_Lab_5_real_T_0;
EXTERN_C volatile real_T *p_5_Lab_5_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Lab_5_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_Lab_5_trc_ptr_h_ */
