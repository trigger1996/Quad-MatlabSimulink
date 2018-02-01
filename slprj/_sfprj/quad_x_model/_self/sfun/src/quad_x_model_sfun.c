/* Include files */

#include "quad_x_model_sfun.h"
#include "quad_x_model_sfun_debug_macros.h"
#include "c1_quad_x_model.h"
#include "c2_quad_x_model.h"
#include "c3_quad_x_model.h"
#include "c4_quad_x_model.h"
#include "c5_quad_x_model.h"
#include "c6_quad_x_model.h"
#include "c7_quad_x_model.h"
#include "c8_quad_x_model.h"
#include "c9_quad_x_model.h"
#include "c10_quad_x_model.h"
#include "c11_quad_x_model.h"
#include "c12_quad_x_model.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _quad_x_modelMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void quad_x_model_initializer(void)
{
}

void quad_x_model_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_quad_x_model_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_quad_x_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_quad_x_model_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_quad_x_model_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4056817098U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(263146550U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3512847235U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3962074393U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1804249517U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(698498326U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2084175359U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1961516227U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c1_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c2_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c3_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c4_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c5_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c6_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c7_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c8_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c9_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c10_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c11_quad_x_model_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_quad_x_model_get_check_sum(mxArray *plhs[]);
          sf_c12_quad_x_model_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(291534296U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1654053042U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(271283110U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4035966165U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_quad_x_model_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(aiChksum, "CNTCXxLoSilASUBtYhJMuF") == 0) {
          extern mxArray *sf_c1_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c1_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "H8mF2kz5a8uufriB49NZpF") == 0) {
          extern mxArray *sf_c2_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c2_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "3M83PPenfCOj7m5mC7E2YD") == 0) {
          extern mxArray *sf_c3_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c3_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "JE0RKfGrWPSofJG4kEIszF") == 0) {
          extern mxArray *sf_c4_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c4_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "wd1hUEzKESrqs4KV9HCE5E") == 0) {
          extern mxArray *sf_c5_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c5_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "BJAyZHUIw9llGz32pyWKFD") == 0) {
          extern mxArray *sf_c6_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c6_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "H3GnCSL7QSKjQfXtBxmXVG") == 0) {
          extern mxArray *sf_c7_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c7_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "ApOcqUyVMO2euL9uwS9deF") == 0) {
          extern mxArray *sf_c8_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c8_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "cKiZBokO0oZ5hiXf3Xv7hE") == 0) {
          extern mxArray *sf_c9_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c9_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "3g00tv1isj5ozH6ehcWmZG") == 0) {
          extern mxArray *sf_c10_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c10_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "QlKMtZGjMTQoZuu7BRA65B") == 0) {
          extern mxArray *sf_c11_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c11_quad_x_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "j8ZlEjiJZUmR8TS5tG2LYC") == 0) {
          extern mxArray *sf_c12_quad_x_model_get_autoinheritance_info(void);
          plhs[0] = sf_c12_quad_x_model_get_autoinheritance_info();
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

unsigned int sf_quad_x_model_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        extern const mxArray *sf_c1_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_quad_x_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_quad_x_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_quad_x_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_quad_x_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_quad_x_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_quad_x_model_get_eml_resolved_functions_info();
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

unsigned int sf_quad_x_model_third_party_uses_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(tpChksum, "mKTZ4WXOXdmjSPiMsxKqDB") == 0) {
          extern mxArray *sf_c1_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c1_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "8YNlz7pac3NC4ca038W3ZE") == 0) {
          extern mxArray *sf_c2_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c2_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "7rPw95Iar25h6dNtnRrERC") == 0) {
          extern mxArray *sf_c3_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c3_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "NimUUaEJwAIJElSUz7bYm") == 0) {
          extern mxArray *sf_c4_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c4_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "nVJVoQKPNS5EnUIGU6ffgC") == 0) {
          extern mxArray *sf_c5_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c5_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "XcdcsBHzJ7QbfJpnCzGS2") == 0) {
          extern mxArray *sf_c6_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c6_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "wLjUcJsDUqeanbdntZSMP") == 0) {
          extern mxArray *sf_c7_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c7_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "kQqLBaQTnkLe6RvBTXznQD") == 0) {
          extern mxArray *sf_c8_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c8_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "wBUbC1dcFw2iESKuqcDyL") == 0) {
          extern mxArray *sf_c9_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c9_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ncI7eeIOjoIcfTixlJLNJD") == 0) {
          extern mxArray *sf_c10_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c10_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "74PZi7quYZXSPCGHfZLZbB") == 0) {
          extern mxArray *sf_c11_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c11_quad_x_model_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "o0BNFhFejoctW18AH6VhMC") == 0) {
          extern mxArray *sf_c12_quad_x_model_third_party_uses_info(void);
          plhs[0] = sf_c12_quad_x_model_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_quad_x_model_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "mKTZ4WXOXdmjSPiMsxKqDB") == 0) {
          extern mxArray *sf_c1_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c1_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "8YNlz7pac3NC4ca038W3ZE") == 0) {
          extern mxArray *sf_c2_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c2_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "7rPw95Iar25h6dNtnRrERC") == 0) {
          extern mxArray *sf_c3_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c3_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "NimUUaEJwAIJElSUz7bYm") == 0) {
          extern mxArray *sf_c4_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c4_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "nVJVoQKPNS5EnUIGU6ffgC") == 0) {
          extern mxArray *sf_c5_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c5_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "XcdcsBHzJ7QbfJpnCzGS2") == 0) {
          extern mxArray *sf_c6_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c6_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "wLjUcJsDUqeanbdntZSMP") == 0) {
          extern mxArray *sf_c7_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c7_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "kQqLBaQTnkLe6RvBTXznQD") == 0) {
          extern mxArray *sf_c8_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c8_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "wBUbC1dcFw2iESKuqcDyL") == 0) {
          extern mxArray *sf_c9_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c9_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ncI7eeIOjoIcfTixlJLNJD") == 0) {
          extern mxArray *sf_c10_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c10_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "74PZi7quYZXSPCGHfZLZbB") == 0) {
          extern mxArray *sf_c11_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c11_quad_x_model_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "o0BNFhFejoctW18AH6VhMC") == 0) {
          extern mxArray *sf_c12_quad_x_model_jit_fallback_info(void);
          plhs[0] = sf_c12_quad_x_model_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_quad_x_model_updateBuildInfo_args_info( int nlhs, mxArray *
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
     case 1:
      {
        if (strcmp(tpChksum, "mKTZ4WXOXdmjSPiMsxKqDB") == 0) {
          extern mxArray *sf_c1_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "8YNlz7pac3NC4ca038W3ZE") == 0) {
          extern mxArray *sf_c2_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "7rPw95Iar25h6dNtnRrERC") == 0) {
          extern mxArray *sf_c3_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "NimUUaEJwAIJElSUz7bYm") == 0) {
          extern mxArray *sf_c4_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "nVJVoQKPNS5EnUIGU6ffgC") == 0) {
          extern mxArray *sf_c5_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "XcdcsBHzJ7QbfJpnCzGS2") == 0) {
          extern mxArray *sf_c6_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "wLjUcJsDUqeanbdntZSMP") == 0) {
          extern mxArray *sf_c7_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "kQqLBaQTnkLe6RvBTXznQD") == 0) {
          extern mxArray *sf_c8_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "wBUbC1dcFw2iESKuqcDyL") == 0) {
          extern mxArray *sf_c9_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ncI7eeIOjoIcfTixlJLNJD") == 0) {
          extern mxArray *sf_c10_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "74PZi7quYZXSPCGHfZLZbB") == 0) {
          extern mxArray *sf_c11_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "o0BNFhFejoctW18AH6VhMC") == 0) {
          extern mxArray *sf_c12_quad_x_model_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_quad_x_model_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_quad_x_model_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "mKTZ4WXOXdmjSPiMsxKqDB") == 0) {
        extern mxArray *sf_c1_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c1_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "8YNlz7pac3NC4ca038W3ZE") == 0) {
        extern mxArray *sf_c2_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c2_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "7rPw95Iar25h6dNtnRrERC") == 0) {
        extern mxArray *sf_c3_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c3_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "NimUUaEJwAIJElSUz7bYm") == 0) {
        extern mxArray *sf_c4_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c4_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "nVJVoQKPNS5EnUIGU6ffgC") == 0) {
        extern mxArray *sf_c5_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c5_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "XcdcsBHzJ7QbfJpnCzGS2") == 0) {
        extern mxArray *sf_c6_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c6_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "wLjUcJsDUqeanbdntZSMP") == 0) {
        extern mxArray *sf_c7_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c7_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "kQqLBaQTnkLe6RvBTXznQD") == 0) {
        extern mxArray *sf_c8_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c8_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "wBUbC1dcFw2iESKuqcDyL") == 0) {
        extern mxArray *sf_c9_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c9_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "ncI7eeIOjoIcfTixlJLNJD") == 0) {
        extern mxArray *sf_c10_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c10_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "74PZi7quYZXSPCGHfZLZbB") == 0) {
        extern mxArray *sf_c11_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c11_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "o0BNFhFejoctW18AH6VhMC") == 0) {
        extern mxArray *sf_c12_quad_x_model_get_post_codegen_info(void);
        plhs[0] = sf_c12_quad_x_model_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void quad_x_model_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _quad_x_modelMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "quad_x_model","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _quad_x_modelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_quad_x_modelMachineNumber_,
    0);
}

void quad_x_model_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_quad_x_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("quad_x_model",
      "quad_x_model");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_quad_x_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
