#ifndef __c3_quad_x_train_h__
#define __c3_quad_x_train_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_quad_x_trainInstanceStruct
#define typedef_SFc3_quad_x_trainInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_quad_x_train;
  real_T *c3_wm1;
  real_T *c3_y;
  real_T *c3_wm2;
  real_T *c3_wm3;
  real_T *c3_wm4;
} SFc3_quad_x_trainInstanceStruct;

#endif                                 /*typedef_SFc3_quad_x_trainInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_quad_x_train_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_quad_x_train_get_check_sum(mxArray *plhs[]);
extern void c3_quad_x_train_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
