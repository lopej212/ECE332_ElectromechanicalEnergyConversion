/*********************** dSPACE target specific file *************************

   Header file Lab6_OpenLoop_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.9 (02-Nov-2017)
   Fri Mar  6 12:55:20 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Lab6_OpenLoop_trc_ptr_h_
#define RTI_HEADER_Lab6_OpenLoop_trc_ptr_h_

/* Include the model header file. */
#include "Lab6_OpenLoop.h"
#include "Lab6_OpenLoop_private.h"
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
EXTERN_C volatile real_T *p_0_Lab6_OpenLoop_real_T_0;
EXTERN_C volatile real_T *p_0_Lab6_OpenLoop_real_T_1;
EXTERN_C volatile real_T *p_0_Lab6_OpenLoop_real_T_2;
EXTERN_C volatile real_T *p_0_Lab6_OpenLoop_real_T_3;
EXTERN_C volatile real_T *p_1_Lab6_OpenLoop_real_T_0;
EXTERN_C volatile int_T *p_2_Lab6_OpenLoop_int_T_0;
EXTERN_C volatile real_T *p_3_Lab6_OpenLoop_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Lab6_OpenLoop_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_Lab6_OpenLoop_trc_ptr_h_ */
