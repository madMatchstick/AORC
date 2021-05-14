#ifndef READ_FORCING_H
#define READ_FORCING_H

#include <stdio.h>
#include <string.h>

//DATA STRUCTURE TO HOLD AORC FORCING DATA
struct aorc_forcing
{
  
  // Read this from the configuration file.
  char* forcing_file;
  
  // ***********************************************************
  // ******************* Dynamic allocations *******************
  // ***********************************************************
  //aorc_forcing_data* forcings;
  double* forcing_data_precip_kg_per_m2;
  double* forcing_data_surface_pressure_Pa;
  double* forcing_data_time;
  double* forcing_data_incoming_longwave_W_per_m2 ;     // Downward Long-Wave Rad. Flux at 0m height, W/m^2       | DLWRF_surface
  double* forcing_data_incoming_shortwave_W_per_m2;     // Downward Short-Wave Radiation Flux at 0m height, W/m^2 | DSWRF_surface
  double* forcing_data_specific_humidity_2m_kg_per_kg;  // Specific Humidity at 2m height, kg/kg                  | SPFH_2maboveground
  double* forcing_data_air_temperature_2m_K;            // Air temparture at 2m height, K                         | TMP_2maboveground
  double* forcing_data_u_wind_speed_10m_m_per_s;        // U-component of Wind at 10m height, m/s                 | UGRD_10maboveground
  double* forcing_data_v_wind_speed_10m_m_per_s;        // V-component of Wind at 10m height, m/s                 | VGRD_10maboveground

  // ***********************************************************
  // ******************* Single values for line read ***********
  // ***********************************************************
  // struct NAME                          DESCRIPTION                                            ORIGINAL AORC NAME     
  //____________________________________________________________________________________________________________________
  float precip_kg_per_m2;                // Surface precipitation "kg/m^2"                         | APCP_surface
  float incoming_longwave_W_per_m2 ;     // Downward Long-Wave Rad. Flux at 0m height, W/m^2       | DLWRF_surface
  float incoming_shortwave_W_per_m2;     // Downward Short-Wave Radiation Flux at 0m height, W/m^2 | DSWRF_surface
  float surface_pressure_Pa;             // Surface atmospheric pressure, Pa                       | PRES_surface
  float specific_humidity_2m_kg_per_kg;  // Specific Humidity at 2m height, kg/kg                  | SPFH_2maboveground
  float air_temperature_2m_K;            // Air temparture at 2m height, K                         | TMP_2maboveground
  float u_wind_speed_10m_m_per_s;        // U-component of Wind at 10m height, m/s                 | UGRD_10maboveground
  float v_wind_speed_10m_m_per_s;        // V-component of Wind at 10m height, m/s                 | VGRD_10maboveground
  double time; //TODO: type?           // seconds since 1970-01-01 00:00:00.0 0:00               | time
  
};
typedef struct aorc_forcing aorc_forcing;

extern void alloc_aorc_model(aorc_forcing *aorc);

extern void free_aorc_model(aorc_forcing *aorc);

extern void parse_aorc_line_et(char *theString,long *year,long *month, long *day,long *hour,
                            long *minute, double *dsec, struct aorc_forcing *aorc);

extern void get_word_aorc(char *theString,int *start,int *end,char *theWord,int *wordlen);
extern void itwo_alloc_aorc( int ***ptr, int x, int y);
extern void dtwo_alloc_aorc( double ***ptr, int x, int y);
extern void d_alloc_aorc(double **var,int size);
extern void i_alloc(int **var,int size);
extern double greg_2_jul_aorc(long year, long mon, long day, long h, long mi, double se);
extern void calc_date_aorc(double jd, long *y, long *m, long *d, long *h, long *mi, double *sec);
#endif