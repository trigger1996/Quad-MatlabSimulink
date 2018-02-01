#ifndef __c4_quad_x_model_h__
#define __c4_quad_x_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_quad_x_modelInstanceStruct
#define typedef_SFc4_quad_x_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_quad_x_model;
  real_T *c4_roll;
  real_T *c4_wm1;
  real_T *c4_pitch;
  real_T *c4_yaw;
  real_T *c4_thurst;
  real_T *c4_wm2;
  real_T *c4_wm3;
  real_T *c4_wm4;
} SFc4_quad_x_modelInstanceStruct;

#endif                                 /*typedef_SFc4_quad_x_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_quad_x_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_quad_x_model_get_check_sum(mxArray *plhs[]);
extern void c4_quad_x_model_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
