/* Include files */

#include <stddef.h>
#include "blas.h"
#include "quad_x_model_sfun.h"
#include "c8_quad_x_model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quad_x_model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[8] = { "k1", "nargin", "nargout",
  "wm1", "wm2", "wm3", "wm4", "y" };

/* Function Declarations */
static void initialize_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void initialize_params_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void enable_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void disable_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_quad_x_model
  (SFc8_quad_x_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_quad_x_model
  (SFc8_quad_x_modelInstanceStruct *chartInstance);
static void set_sim_state_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void sf_gateway_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void mdl_start_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void initSimStructsc8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct *chartInstance,
  const mxArray *c8_b_y, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_eml_scalar_eg(SFc8_quad_x_modelInstanceStruct *chartInstance);
static real_T c8_mpower(SFc8_quad_x_modelInstanceStruct *chartInstance, real_T
  c8_a);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_c_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_d_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_quad_x_model, const char_T
  *c8_identifier);
static uint8_T c8_e_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_quad_x_modelInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc8_quad_x_modelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_quad_x_model = 0U;
}

static void initialize_params_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_quad_x_model
  (SFc8_quad_x_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_quad_x_model
  (SFc8_quad_x_modelInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_b_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_d_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createcellmatrix(2, 1), false);
  c8_hoistedGlobal = *chartInstance->c8_y;
  c8_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_b_y, 0, c8_c_y);
  c8_b_hoistedGlobal = chartInstance->c8_is_active_c8_quad_x_model;
  c8_b_u = c8_b_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_b_y, 1, c8_d_y);
  sf_mex_assign(&c8_st, c8_b_y, false);
  return c8_st;
}

static void set_sim_state_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  *chartInstance->c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 0)), "y");
  chartInstance->c8_is_active_c8_quad_x_model = c8_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_quad_x_model");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_quad_x_model(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_d_hoistedGlobal;
  real_T c8_b_wm1;
  real_T c8_b_wm2;
  real_T c8_b_wm3;
  real_T c8_b_wm4;
  uint32_T c8_debug_family_var_map[8];
  real_T c8_k1;
  real_T c8_nargin = 4.0;
  real_T c8_nargout = 1.0;
  real_T c8_b_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_wm1, 0U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *chartInstance->c8_wm1;
  c8_b_hoistedGlobal = *chartInstance->c8_wm2;
  c8_c_hoistedGlobal = *chartInstance->c8_wm3;
  c8_d_hoistedGlobal = *chartInstance->c8_wm4;
  c8_b_wm1 = c8_hoistedGlobal;
  c8_b_wm2 = c8_b_hoistedGlobal;
  c8_b_wm3 = c8_c_hoistedGlobal;
  c8_b_wm4 = c8_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_k1, 0U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_wm1, 3U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_wm2, 4U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_wm3, 5U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_wm4, 6U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_k1 = 3.1E-7;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_b_y = 3.1E-7 * (((c8_mpower(chartInstance, c8_b_wm1) + c8_mpower
                       (chartInstance, c8_b_wm2)) + c8_mpower(chartInstance,
    c8_b_wm3)) + c8_mpower(chartInstance, c8_b_wm4));
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c8_y = c8_b_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_quad_x_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_y, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_wm2, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_wm3, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_wm4, 4U);
}

static void mdl_start_c8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_quad_x_model(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  SFc8_quad_x_modelInstanceStruct *chartInstance;
  chartInstance = (SFc8_quad_x_modelInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct *chartInstance,
  const mxArray *c8_b_y, const char_T *c8_identifier)
{
  real_T c8_c_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_c_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  return c8_c_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_b_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_b_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_b_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_c_y;
  SFc8_quad_x_modelInstanceStruct *chartInstance;
  chartInstance = (SFc8_quad_x_modelInstanceStruct *)chartInstanceVoid;
  c8_b_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_c_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  *(real_T *)c8_outData = c8_c_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_quad_x_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  const mxArray *c8_rhs10 = NULL;
  const mxArray *c8_lhs10 = NULL;
  const mxArray *c8_rhs11 = NULL;
  const mxArray *c8_lhs11 = NULL;
  const mxArray *c8_rhs12 = NULL;
  const mxArray *c8_lhs12 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395303306U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c8_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c8_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c8_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
  sf_mex_destroy(&c8_rhs10);
  sf_mex_destroy(&c8_lhs10);
  sf_mex_destroy(&c8_rhs11);
  sf_mex_destroy(&c8_lhs11);
  sf_mex_destroy(&c8_rhs12);
  sf_mex_destroy(&c8_lhs12);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_u)
{
  const mxArray *c8_b_y = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), false);
  return c8_b_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u)
{
  const mxArray *c8_b_y = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), false);
  return c8_b_y;
}

static void c8_eml_scalar_eg(SFc8_quad_x_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c8_mpower(SFc8_quad_x_modelInstanceStruct *chartInstance, real_T
  c8_a)
{
  real_T c8_b_a;
  real_T c8_c_a;
  real_T c8_ak;
  real_T c8_d_a;
  c8_b_a = c8_a;
  c8_c_a = c8_b_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_c_a;
  c8_d_a = c8_ak;
  c8_eml_scalar_eg(chartInstance);
  return c8_d_a * c8_d_a;
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_b_y = NULL;
  SFc8_quad_x_modelInstanceStruct *chartInstance;
  chartInstance = (SFc8_quad_x_modelInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_c_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_b_y;
  int32_T c8_i0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i0, 1, 6, 0U, 0, 0U, 0);
  c8_b_y = c8_i0;
  sf_mex_destroy(&c8_u);
  return c8_b_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_b_y;
  SFc8_quad_x_modelInstanceStruct *chartInstance;
  chartInstance = (SFc8_quad_x_modelInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_d_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_quad_x_model, const char_T
  *c8_identifier)
{
  uint8_T c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_quad_x_model), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_quad_x_model);
  return c8_b_y;
}

static uint8_T c8_e_emlrt_marshallIn(SFc8_quad_x_modelInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_b_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_b_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_b_y;
}

static void init_dsm_address_info(SFc8_quad_x_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_quad_x_modelInstanceStruct
  *chartInstance)
{
  chartInstance->c8_wm1 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c8_wm2 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_wm3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c8_wm4 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c8_quad_x_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3740136524U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(154551671U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3954462710U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3097845390U);
}

mxArray* sf_c8_quad_x_model_get_post_codegen_info(void);
mxArray *sf_c8_quad_x_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ApOcqUyVMO2euL9uwS9deF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c8_quad_x_model_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_quad_x_model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_quad_x_model_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_quad_x_model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_quad_x_model_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c8_quad_x_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c8_quad_x_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_quad_x_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_quad_x_modelInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_quad_x_modelInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _quad_x_modelMachineNumber_,
           8,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_quad_x_modelMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_quad_x_modelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _quad_x_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"wm1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"wm2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"wm3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"wm4");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,114);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c8_wm1);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_y);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c8_wm2);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c8_wm3);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c8_wm4);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _quad_x_modelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "kQqLBaQTnkLe6RvBTXznQD";
}

static void sf_opaque_initialize_c8_quad_x_model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_quad_x_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*)
    chartInstanceVar);
  initialize_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_quad_x_model(void *chartInstanceVar)
{
  enable_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_quad_x_model(void *chartInstanceVar)
{
  disable_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_quad_x_model(void *chartInstanceVar)
{
  sf_gateway_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_quad_x_model(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_quad_x_model(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c8_quad_x_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_quad_x_model_optimization_info();
    }

    finalize_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_quad_x_model((SFc8_quad_x_modelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_quad_x_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c8_quad_x_model((SFc8_quad_x_modelInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_quad_x_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quad_x_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1049021892U));
  ssSetChecksum1(S,(126769183U));
  ssSetChecksum2(S,(1694443143U));
  ssSetChecksum3(S,(1416408732U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_quad_x_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_quad_x_model(SimStruct *S)
{
  SFc8_quad_x_modelInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_quad_x_modelInstanceStruct *)utMalloc(sizeof
    (SFc8_quad_x_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_quad_x_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_quad_x_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_quad_x_model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_quad_x_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_quad_x_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_quad_x_model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_quad_x_model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_quad_x_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_quad_x_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_quad_x_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_quad_x_model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_quad_x_model;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c8_quad_x_model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_quad_x_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_quad_x_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_quad_x_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_quad_x_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
