#ifndef __c10_quad_x_model_h__
#define __c10_quad_x_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_quad_x_modelInstanceStruct
#define typedef_SFc10_quad_x_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_quad_x_model;
  real_T *c10_u4;
  real_T *c10_roll;
  real_T *c10_pitch;
  real_T *c10_ay;
  real_T *c10_yaw;
  real_T *c10_vy;
} SFc10_quad_x_modelInstanceStruct;

#endif                                 /*typedef_SFc10_quad_x_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_quad_x_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_quad_x_model_get_check_sum(mxArray *plhs[]);
extern void c10_quad_x_model_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
