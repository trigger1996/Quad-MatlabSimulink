#ifndef __c11_quad_iris_model_h__
#define __c11_quad_iris_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_quad_iris_modelInstanceStruct
#define typedef_SFc11_quad_iris_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_quad_iris_model;
  real_T *c11_thurst;
  real_T *c11_roll;
  real_T *c11_pitch;
  real_T *c11_az;
  real_T *c11_yaw;
  real_T *c11_vz;
} SFc11_quad_iris_modelInstanceStruct;

#endif                                 /*typedef_SFc11_quad_iris_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_quad_iris_model_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c11_quad_iris_model_get_check_sum(mxArray *plhs[]);
extern void c11_quad_iris_model_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
