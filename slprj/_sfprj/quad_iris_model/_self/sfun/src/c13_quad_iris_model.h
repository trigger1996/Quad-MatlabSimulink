#ifndef __c13_quad_iris_model_h__
#define __c13_quad_iris_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_quad_iris_modelInstanceStruct
#define typedef_SFc13_quad_iris_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_quad_iris_model;
  real_T *c13_wm1;
  real_T *c13_wm2;
  real_T *c13_wm3;
  real_T *c13_wm4;
  real_T *c13_alpha_x;
  real_T *c13_alpha_y;
  real_T *c13_alpha_z;
  real_T *c13_wx;
  real_T *c13_wy;
  real_T *c13_wz;
} SFc13_quad_iris_modelInstanceStruct;

#endif                                 /*typedef_SFc13_quad_iris_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_quad_iris_model_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_quad_iris_model_get_check_sum(mxArray *plhs[]);
extern void c13_quad_iris_model_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
