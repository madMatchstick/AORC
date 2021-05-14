#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/bmi.h"
#include "../include/et.h"
#include "../include/bmi_et.h"

/*
This main program is a mock framwork.
This is not part of BMI, but acts as the driver that calls the model.
*/
int
 main(int argc, const char *argv[])
{

  // A configuration file is required for running this model through BMI
  if(argc<=1){
    printf("make sure to include a path to the config file\n");
    exit(1);
  }

   printf("allocating memory to store entire BMI structure\n");
  // allocating memory to store the entire BMI structure
  Bmi *et_bmi_model = (Bmi *) malloc(sizeof(Bmi));

  printf("Registering BMI models\n");
  register_bmi_et(et_bmi_model);

  printf("Initializeing BMI models\n");
  const char *cfg_file_et = argv[1];
  et_bmi_model->initialize(et_bmi_model, cfg_file_et);

  printf("Get the information from the configuration here in Main\n");
  et_model *et;
  et = (et_model *) et_bmi_model->data;
  printf("forcing file for the ET module %s\n", et->forcing_file);

  printf("Updating models\n");
  et_bmi_model->update(et_bmi_model);

  printf("looping through and calling update\n");
  int i=0;
  for (i = 0; i < 2; i++){
    // The unit test only runs one time step.
    if (et->bmi.run_unit_tests == 0){
      et_bmi_model->update(et_bmi_model);
      printf("potential evapotranspiration (m s-1): %8.4e\n", et->et_m_per_s);
      printf("--------------------- END OF TIMESTEP ---------------------------------\n");
    }
  }

  printf("Finalizing models\n");
  et_bmi_model->finalize(et_bmi_model);

  return 0;
}

