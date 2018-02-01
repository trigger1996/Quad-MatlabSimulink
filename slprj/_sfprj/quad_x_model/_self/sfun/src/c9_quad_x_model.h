#ifndef __c9_quad_x_model_h__
#define __c9_quad_x_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_quad_x_modelInstanceStruct
#define typedef_SFc9_quad_x_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_quad_x_model;
  real_T *c9_u4;
  real_T *c9_roll;
  real_T *c9_pitch;
  real_T *c9_ax;
  real_T *c9_yaw;
  real_T *c9_vx;
} SFc9_quad_x_modelInstanceStruct;

#endif                                 /*typedef_SFc9_quad_x_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_quad_x_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_quad_x_model_get_check_sum(mxArray *plhs[]);
extern void c9_quad_x_model_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
