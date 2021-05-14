#!/bin/bash
touch run_bmi
mv -f run_bmi z_trash
gcc -lm ./src/main.c ./src/aorc.c ./src/bmi_aorc.c -o run_bmi_aorc
./run_bmi_aorc ./configs/aorc_config_cat_67.txt 
