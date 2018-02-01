/* Include files */

#include "quad_iris_model_sfun.h"
#include "quad_iris_model_sfun_debug_macros.h"
#include "c8_quad_iris_model.h"
#include "c9_quad_iris_model.h"
#include "c10_quad_iris_model.h"
#include "c11_quad_iris_model.h"
#include "c13_quad_iris_model.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _quad_iris_modelMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void quad_iris_model_initializer(void)
{
}

void quad_iris_model_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_quad_iris_model_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==8) {
    c8_quad_iris_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_quad_iris_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_quad_iris_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_quad_iris_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_quad_iris_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_quad_iris_model_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_quad_iris_model_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(443007355U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1130630823U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2378074571U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4113090185U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(83197539U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1752861590U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3276851339U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1684581846U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 8:
        {
          extern void sf_c8_quad_iris_model_get_check_sum(mxArray *plhs[]);
          sf_c8_quad_iris_model_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_quad_iris_model_get_check_sum(mxArray *plhs[]);
          sf_c9_quad_iris_model_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_quad_iris_model_get_check_sum(mxArray *plhs[]);
          sf_c10_quad_iris_model_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_quad_iris_model_get_check_sum(mxArray *plhs[]);
          sf_c11_quad_iris_model_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_quad_iris_model_get_check_sum(mxArray *plhs[]);
          sf_c13_quad_iris_model_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1019247060U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1045027730U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2973538032U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3708983399U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_quad_iris_model_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(aiChksum, "7uZMuW0M1AK7X9KiK4rdRB") == 0) {
          extern mxArray *sf_c8_quad_iris_model_get_autoinheritance_info(void);
          plhs[0] = sf_c8_quad_iris_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "Cq8keoiKbYtE0O6iC5XFCE") == 0) {
          extern mxArray *sf_c9_quad_iris_model_get_autoinheritance_info(void);
          plhs[0] = sf_c9_quad_iris_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "mHrTWQwaTPYVl6X88rcAg") == 0) {
          extern mxArray *sf_c10_quad_iris_model_get_autoinheritance_info(void);
          plhs[0] = sf_c10_quad_iris_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "muWtAJGH4cJhNLDhHQJygG") == 0) {
          extern mxArray *sf_c11_quad_iris_model_get_autoinheritance_info(void);
          plhs[0] = sf_c11_quad_iris_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "W0XPjLx6j91ZSWS2fl2OXD") == 0) {
          extern mxArray *sf_c13_quad_iris_model_get_autoinheritance_info(void);
          plhs[0] = sf_c13_quad_iris_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_quad_iris_model_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        extern const mxArray
          *sf_c8_quad_iris_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_quad_iris_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_quad_iris_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_quad_iris_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_quad_iris_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_quad_iris_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_quad_iris_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_quad_iris_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_quad_iris_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_quad_iris_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_quad_iris_model_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "bWBzHLsROgyTCbh97U8PSG") == 0) {
          extern mxArray *sf_c8_quad_iris_model_third_party_uses_info(void);
          plhs[0] = sf_c8_quad_iris_model_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "bnfHB6mNpJvahMtbiovJ7F") == 0) {
          extern mxArray *sf_c9_quad_iris_model_third_party_uses_info(void);
          plhs[0] = sf_c9_quad_iris_model_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "hjlZCfEtXN7GXsw631ZTyG") == 0) {
          extern mxArray *sf_c10_quad_iris_model_third_party_uses_info(void);
          plhs[0] = sf_c10_quad_iris_model_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "4QiKBj9s93kM6Z77hZqyfF") == 0) {
          extern mxArray *sf_c11_quad_iris_model_third_party_uses_info(void);
          plhs[0] = sf_c11_quad_iris_model_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "DRBmW5sbJrvz3o0nhrOhsB") == 0) {
          extern mxArray *sf_c13_quad_iris_model_third_party_uses_info(void);
          plhs[0] = sf_c13_quad_iris_model_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_quad_iris_model_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "bWBzHLsROgyTCbh97U8PSG") == 0) {
          extern mxArray *sf_c8_quad_iris_model_jit_fallback_info(void);
          plhs[0] = sf_c8_quad_iris_model_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "bnfHB6mNpJvahMtbiovJ7F") == 0) {
          extern mxArray *sf_c9_quad_iris_model_jit_fallback_info(void);
          plhs[0] = sf_c9_quad_iris_model_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "hjlZCfEtXN7GXsw631ZTyG") == 0) {
          extern mxArray *sf_c10_quad_iris_model_jit_fallback_info(void);
          plhs[0] = sf_c10_quad_iris_model_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "4QiKBj9s93kM6Z77hZqyfF") == 0) {
          extern mxArray *sf_c11_quad_iris_model_jit_fallback_info(void);
          plhs[0] = sf_c11_quad_iris_model_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "DRBmW5sbJrvz3o0nhrOhsB") == 0) {
          extern mxArray *sf_c13_quad_iris_model_jit_fallback_info(void);
          plhs[0] = sf_c13_quad_iris_model_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_quad_iris_model_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "bWBzHLsROgyTCbh97U8PSG") == 0) {
          extern mxArray *sf_c8_quad_iris_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_quad_iris_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "bnfHB6mNpJvahMtbiovJ7F") == 0) {
          extern mxArray *sf_c9_quad_iris_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_quad_iris_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "hjlZCfEtXN7GXsw631ZTyG") == 0) {
          extern mxArray *sf_c10_quad_iris_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_quad_iris_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "4QiKBj9s93kM6Z77hZqyfF") == 0) {
          extern mxArray *sf_c11_quad_iris_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_quad_iris_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "DRBmW5sbJrvz3o0nhrOhsB") == 0) {
          extern mxArray *sf_c13_quad_iris_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_quad_iris_model_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_quad_iris_model_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 8:
    {
      if (strcmp(tpChksum, "bWBzHLsROgyTCbh97U8PSG") == 0) {
        extern mxArray *sf_c8_quad_iris_model_get_post_codegen_info(void);
        plhs[0] = sf_c8_quad_iris_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "bnfHB6mNpJvahMtbiovJ7F") == 0) {
        extern mxArray *sf_c9_quad_iris_model_get_post_codegen_info(void);
        plhs[0] = sf_c9_quad_iris_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "hjlZCfEtXN7GXsw631ZTyG") == 0) {
        extern mxArray *sf_c10_quad_iris_model_get_post_codegen_info(void);
        plhs[0] = sf_c10_quad_iris_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "4QiKBj9s93kM6Z77hZqyfF") == 0) {
        extern mxArray *sf_c11_quad_iris_model_get_post_codegen_info(void);
        plhs[0] = sf_c11_quad_iris_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "DRBmW5sbJrvz3o0nhrOhsB") == 0) {
        extern mxArray *sf_c13_quad_iris_model_get_post_codegen_info(void);
        plhs[0] = sf_c13_quad_iris_model_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void quad_iris_model_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _quad_iris_modelMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "quad_iris_model","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _quad_iris_modelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _quad_iris_modelMachineNumber_,0);
}

void quad_iris_model_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_quad_iris_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("quad_iris_model",
      "quad_iris_model");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_quad_iris_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
