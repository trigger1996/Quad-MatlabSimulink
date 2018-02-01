/* Include files */

#include <stddef.h>
#include "blas.h"
#include "quad_x_train_sfun.h"
#include "c12_quad_x_train.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quad_x_train_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c12_debug_family_names[6] = { "nargin", "nargout", "wm1",
  "wm2", "wm3", "wm4" };

/* Function Declarations */
static void initialize_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void initialize_params_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct *
  chartInstance);
static void enable_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void disable_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_quad_x_train
  (SFc12_quad_x_trainInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_quad_x_train
  (SFc12_quad_x_trainInstanceStruct *chartInstance);
static void set_sim_state_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void sf_gateway_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void mdl_start_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void initSimStructsc12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_b_wm4, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_c_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_d_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_quad_x_train, const char_T *
  c12_identifier);
static uint8_T c12_e_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_quad_x_trainInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc12_quad_x_trainInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_is_active_c12_quad_x_train = 0U;
}

static void initialize_params_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_quad_x_train
  (SFc12_quad_x_trainInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_quad_x_train
  (SFc12_quad_x_trainInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_hoistedGlobal;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_hoistedGlobal;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_d_hoistedGlobal;
  real_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  uint8_T c12_e_hoistedGlobal;
  uint8_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(5, 1), false);
  c12_hoistedGlobal = *chartInstance->c12_wm1;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = *chartInstance->c12_wm2;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_hoistedGlobal = *chartInstance->c12_wm3;
  c12_c_u = c12_c_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_d_hoistedGlobal = *chartInstance->c12_wm4;
  c12_d_u = c12_d_hoistedGlobal;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_e_hoistedGlobal = chartInstance->c12_is_active_c12_quad_x_train;
  c12_e_u = c12_e_hoistedGlobal;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 4, c12_f_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  *chartInstance->c12_wm1 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 0)), "wm1");
  *chartInstance->c12_wm2 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "wm2");
  *chartInstance->c12_wm3 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 2)), "wm3");
  *chartInstance->c12_wm4 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 3)), "wm4");
  chartInstance->c12_is_active_c12_quad_x_train = c12_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 4)),
     "is_active_c12_quad_x_train");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_quad_x_train(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  uint32_T c12_debug_family_var_map[6];
  real_T c12_nargin = 0.0;
  real_T c12_nargout = 4.0;
  real_T c12_b_wm1;
  real_T c12_b_wm2;
  real_T c12_b_wm3;
  real_T c12_b_wm4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_wm1, 2U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_wm2, 3U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_wm3, 4U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_wm4, 5U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
  c12_b_wm1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 7);
  c12_b_wm2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 8);
  c12_b_wm3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  c12_b_wm4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c12_wm1 = c12_b_wm1;
  *chartInstance->c12_wm2 = c12_b_wm2;
  *chartInstance->c12_wm3 = c12_b_wm3;
  *chartInstance->c12_wm4 = c12_b_wm4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_quad_x_trainMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_wm1, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_wm2, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_wm3, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_wm4, 3U);
}

static void mdl_start_c12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc12_quad_x_train(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_quad_x_trainInstanceStruct *chartInstance;
  chartInstance = (SFc12_quad_x_trainInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_b_wm4, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_wm4),
    &c12_thisId);
  sf_mex_destroy(&c12_b_wm4);
  return c12_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_wm4;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_quad_x_trainInstanceStruct *chartInstance;
  chartInstance = (SFc12_quad_x_trainInstanceStruct *)chartInstanceVoid;
  c12_b_wm4 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_wm4),
    &c12_thisId);
  sf_mex_destroy(&c12_b_wm4);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_quad_x_train_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_quad_x_trainInstanceStruct *chartInstance;
  chartInstance = (SFc12_quad_x_trainInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_c_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i0, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_quad_x_trainInstanceStruct *chartInstance;
  chartInstance = (SFc12_quad_x_trainInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_d_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_quad_x_train, const char_T *
  c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_quad_x_train), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_quad_x_train);
  return c12_y;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_quad_x_trainInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc12_quad_x_trainInstanceStruct
  *chartInstance)
{
  chartInstance->c12_wm1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_wm2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_wm3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_wm4 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c12_quad_x_train_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2669793736U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(33542652U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(655192973U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4244025251U);
}

mxArray* sf_c12_quad_x_train_get_post_codegen_info(void);
mxArray *sf_c12_quad_x_train_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("j8ZlEjiJZUmR8TS5tG2LYC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c12_quad_x_train_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_quad_x_train_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_quad_x_train_jit_fallback_info(void)
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

mxArray *sf_c12_quad_x_train_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_quad_x_train_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c12_quad_x_train(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"wm1\",},{M[1],M[6],T\"wm2\",},{M[1],M[7],T\"wm3\",},{M[1],M[8],T\"wm4\",},{M[8],M[0],T\"is_active_c12_quad_x_train\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_quad_x_train_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_quad_x_trainInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_quad_x_trainInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _quad_x_trainMachineNumber_,
           12,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_quad_x_trainMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_quad_x_trainMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _quad_x_trainMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"wm1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"wm2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"wm3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"wm4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,101);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c12_wm1);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c12_wm2);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c12_wm3);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c12_wm4);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _quad_x_trainMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "o0BNFhFejoctW18AH6VhMC";
}

static void sf_opaque_initialize_c12_quad_x_train(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_quad_x_trainInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInstanceVar);
  initialize_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_quad_x_train(void *chartInstanceVar)
{
  enable_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_quad_x_train(void *chartInstanceVar)
{
  disable_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_quad_x_train(void *chartInstanceVar)
{
  sf_gateway_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_quad_x_train(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_quad_x_train(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c12_quad_x_train(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_quad_x_trainInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_quad_x_train_optimization_info();
    }

    finalize_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
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
  initSimStructsc12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_quad_x_train(SimStruct *S)
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
    initialize_params_c12_quad_x_train((SFc12_quad_x_trainInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_quad_x_train(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quad_x_train_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3024278338U));
  ssSetChecksum1(S,(4891508U));
  ssSetChecksum2(S,(1599099865U));
  ssSetChecksum3(S,(929334029U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_quad_x_train(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_quad_x_train(SimStruct *S)
{
  SFc12_quad_x_trainInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_quad_x_trainInstanceStruct *)utMalloc(sizeof
    (SFc12_quad_x_trainInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_quad_x_trainInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_quad_x_train;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_quad_x_train;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_quad_x_train;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_quad_x_train;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_quad_x_train;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_quad_x_train;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_quad_x_train;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_quad_x_train;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_quad_x_train;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_quad_x_train;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_quad_x_train;
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

void c12_quad_x_train_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_quad_x_train(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_quad_x_train(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_quad_x_train(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_quad_x_train_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
