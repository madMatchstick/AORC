#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/bmi.h"
#include "../include/aorc.h"
#include "../include/bmi_aorc.h"

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
  Bmi *aorc_bmi_model = (Bmi *) malloc(sizeof(Bmi));

  printf("Registering BMI models\n");
  register_bmi_aorc(aorc_bmi_model);

  printf("Initializeing BMI models\n");
  const char *cfg_file_aorc = argv[1];
  aorc_bmi_model->initialize(aorc_bmi_model, cfg_file_aorc);

  printf("Get the information from the configuration here in Main\n");
  aorc_model *aorc;
  aorc = (aorc_model *) aorc_bmi_model->data;
  printf("forcing file for the AORC module %s\n", aorc->forcing_file);

  printf("Updating models\n");
  aorc_bmi_model->update(aorc_bmi_model);

  printf("looping through and calling update\n");
  int i=0;
  for (i = 0; i < 5; i++){
    // The unit test only runs one time step.
    if (aorc->bmi.run_unit_tests == 0){
      aorc_bmi_model->update(aorc_bmi_model);
      printf("AORC Precipitation %8.4lf\n", aorc->aorc.precip_kg_per_m2);
      printf("AORC Surface Pressure %8.4lf\n", aorc->aorc.surface_pressure_Pa);
      printf("AORC Longwave radiation %8.4lf\n", aorc->aorc.incoming_longwave_W_per_m2);
      printf("AORC Shortwave radiation %8.4lf\n", aorc->aorc.incoming_shortwave_W_per_m2);
      printf("--------------------- END OF TIMESTEP ---------------------------------\n");
    }
  }

  printf("Finalizing models\n");
  aorc_bmi_model->finalize(aorc_bmi_model);

  return 0;
}

