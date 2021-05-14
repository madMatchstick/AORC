# Basic Model Interface (BMI) for AORC atmospheric forcings
Read in and prepare AORC forcing data for use in NGen water modeling framework. Specifically to test the Modules.

# The configuration file (./configs/et_config*.txt)
Many options are available when running this forcing module.

# Compiling this code
The BMI functionality was developed as a standalone module in C. To compile this code the developer used these steps:
1. `module load gnu/10.1.0`
2. `gcc -lm ./src/main.c ./src/read_aorc_forcing.c ./src/bmi_aorc.c -o run_bmi`
This should generate an executable called **run_bmi**. To run this executable you must pass the path to corresponding to the corresponding configuration file.

Included in this repository is an environment file (env_cheyenne.sh), and a "make and run" file (make_and_run.sh), which will compile the code and run the atmospheric forcing BMI. If you are on the Cheyenne computer, or if you can modify these files to your machine, you can simply follow these two steps to run this code:
1. `source env_cheyenne.sh`
2. `./make_and_run.sh`