/* Include files */

#include <stddef.h>
#include "blas.h"
#include "quad_iris_model_sfun.h"
#include "c9_quad_iris_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quad_iris_model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[11] = { "m", "g", "kf", "nargin",
  "nargout", "thurst", "roll", "pitch", "yaw", "vx", "ax" };

/* Function Declarations */
static void initialize_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void initialize_params_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance);
static void enable_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void disable_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance);
static void set_sim_state_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct *
  chartInstance, const mxArray *c9_st);
static void finalize_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void sf_gateway_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void mdl_start_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void initSimStructsc9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_b_ax, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_quad_iris_model, const char_T
  *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_quad_iris_modelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_quad_iris_model = 0U;
}

static void initialize_params_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_quad_iris_model
  (SFc9_quad_iris_modelInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(2, 1), false);
  c9_hoistedGlobal = *chartInstance->c9_ax;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = chartInstance->c9_is_active_c9_quad_iris_model;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct *
  chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  *chartInstance->c9_ax = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 0)), "ax");
  chartInstance->c9_is_active_c9_quad_iris_model = c9_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
     "is_active_c9_quad_iris_model");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_quad_iris_model(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_b_thurst;
  real_T c9_b_roll;
  real_T c9_b_pitch;
  real_T c9_b_yaw;
  real_T c9_b_vx;
  uint32_T c9_debug_family_var_map[11];
  real_T c9_m;
  real_T c9_g;
  real_T c9_kf;
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 1.0;
  real_T c9_b_ax;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_A;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_thurst, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_roll, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_pitch, 2U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *chartInstance->c9_thurst;
  c9_b_hoistedGlobal = *chartInstance->c9_roll;
  c9_c_hoistedGlobal = *chartInstance->c9_pitch;
  c9_d_hoistedGlobal = *chartInstance->c9_yaw;
  c9_e_hoistedGlobal = *chartInstance->c9_vx;
  c9_b_thurst = c9_hoistedGlobal;
  c9_b_roll = c9_b_hoistedGlobal;
  c9_b_pitch = c9_c_hoistedGlobal;
  c9_b_yaw = c9_d_hoistedGlobal;
  c9_b_vx = c9_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_m, 0U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_kf, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_thurst, 5U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_roll, 6U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_pitch, 7U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_yaw, 8U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_vx, 9U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_ax, 10U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_m = 0.25;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_kf = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_x = c9_b_roll;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarSin(c9_b_x);
  c9_c_x = c9_b_yaw;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarSin(c9_d_x);
  c9_e_x = c9_b_roll;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarCos(c9_f_x);
  c9_g_x = c9_b_pitch;
  c9_h_x = c9_g_x;
  c9_h_x = muDoubleScalarSin(c9_h_x);
  c9_i_x = c9_b_yaw;
  c9_j_x = c9_i_x;
  c9_j_x = muDoubleScalarCos(c9_j_x);
  c9_b_ax = c9_b_thurst * (c9_b_x * c9_d_x + c9_f_x * c9_h_x * c9_j_x);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_b_ax -= 0.0 * c9_b_vx;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_A = c9_b_ax;
  c9_k_x = c9_A;
  c9_l_x = c9_k_x;
  c9_m_x = c9_l_x;
  c9_b_ax = c9_m_x / 0.25;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c9_ax = c9_b_ax;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_quad_iris_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ax, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_yaw, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_vx, 5U);
}

static void mdl_start_c9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_quad_iris_model(SFc9_quad_iris_modelInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_quad_iris_modelInstanceStruct *chartInstance;
  chartInstance = (SFc9_quad_iris_modelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_b_ax, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_ax), &c9_thisId);
  sf_mex_destroy(&c9_b_ax);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_ax;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_quad_iris_modelInstanceStruct *chartInstance;
  chartInstance = (SFc9_quad_iris_modelInstanceStruct *)chartInstanceVoid;
  c9_b_ax = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_ax), &c9_thisId);
  sf_mex_destroy(&c9_b_ax);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_quad_iris_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  const mxArray *c9_rhs7 = NULL;
  const mxArray *c9_lhs7 = NULL;
  const mxArray *c9_rhs8 = NULL;
  const mxArray *c9_lhs8 = NULL;
  const mxArray *c9_rhs9 = NULL;
  const mxArray *c9_lhs9 = NULL;
  const mxArray *c9_rhs10 = NULL;
  const mxArray *c9_lhs10 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("sin"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395303304U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286797136U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("cos"), "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395303296U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286797122U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rdivide"), "name", "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c9_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c9_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_div"), "name", "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c9_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c9_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
  sf_mex_destroy(&c9_rhs7);
  sf_mex_destroy(&c9_lhs7);
  sf_mex_destroy(&c9_rhs8);
  sf_mex_destroy(&c9_lhs8);
  sf_mex_destroy(&c9_rhs9);
  sf_mex_destroy(&c9_lhs9);
  sf_mex_destroy(&c9_rhs10);
  sf_mex_destroy(&c9_lhs10);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_quad_iris_modelInstanceStruct *chartInstance;
  chartInstance = (SFc9_quad_iris_modelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i0, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_quad_iris_modelInstanceStruct *chartInstance;
  chartInstance = (SFc9_quad_iris_modelInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_quad_iris_model, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_quad_iris_model), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_quad_iris_model);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_quad_iris_modelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_quad_iris_modelInstanceStruct
  *chartInstance)
{
  chartInstance->c9_thurst = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_roll = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_pitch = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_ax = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_yaw = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_vx = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
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

void sf_c9_quad_iris_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2673475485U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1698030293U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2364703213U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3596555682U);
}

mxArray* sf_c9_quad_iris_model_get_post_codegen_info(void);
mxArray *sf_c9_quad_iris_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Cq8keoiKbYtE0O6iC5XFCE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c9_quad_iris_model_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_quad_iris_model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_quad_iris_model_jit_fallback_info(void)
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

mxArray *sf_c9_quad_iris_model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_quad_iris_model_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_quad_iris_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ax\",},{M[8],M[0],T\"is_active_c9_quad_iris_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_quad_iris_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_quad_iris_modelInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_quad_iris_modelInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _quad_iris_modelMachineNumber_,
           9,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_quad_iris_modelMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_quad_iris_modelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _quad_iris_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"thurst");
          _SFD_SET_DATA_PROPS(1,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ax");
          _SFD_SET_DATA_PROPS(4,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(5,1,1,0,"vx");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,258);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_thurst);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_roll);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_pitch);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_ax);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_yaw);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_vx);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _quad_iris_modelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bnfHB6mNpJvahMtbiovJ7F";
}

static void sf_opaque_initialize_c9_quad_iris_model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
  initialize_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_quad_iris_model(void *chartInstanceVar)
{
  enable_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_quad_iris_model(void *chartInstanceVar)
{
  disable_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_quad_iris_model(void *chartInstanceVar)
{
  sf_gateway_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_quad_iris_model(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_quad_iris_model(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_quad_iris_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_quad_iris_modelInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_quad_iris_model_optimization_info();
    }

    finalize_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_quad_iris_model(SimStruct *S)
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
    initialize_params_c9_quad_iris_model((SFc9_quad_iris_modelInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_quad_iris_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quad_iris_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(328203012U));
  ssSetChecksum1(S,(1948383183U));
  ssSetChecksum2(S,(4242932763U));
  ssSetChecksum3(S,(1363243004U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_quad_iris_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_quad_iris_model(SimStruct *S)
{
  SFc9_quad_iris_modelInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_quad_iris_modelInstanceStruct *)utMalloc(sizeof
    (SFc9_quad_iris_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_quad_iris_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_quad_iris_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_quad_iris_model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_quad_iris_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_quad_iris_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_quad_iris_model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_quad_iris_model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_quad_iris_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_quad_iris_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_quad_iris_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_quad_iris_model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_quad_iris_model;
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

void c9_quad_iris_model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_quad_iris_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_quad_iris_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_quad_iris_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_quad_iris_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
