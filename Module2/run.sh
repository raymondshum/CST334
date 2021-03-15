# ############################################################
# NAME: Raymond Shum                                         #
# DATE: March 16, 2021                                       #
# TITLE: Lab 3 - Run script                                  #
# DESCRIPTION: This script is not part of the assignment. It #
# compiles and runs both parts of the lab assignment.        #
# ############################################################

# Cleans old executables, compiles programs and creates run1 output.
make clean
make
touch 3_run1.txt

# Run program 1 with 0, 3000, 500, 5000 microsecond delays. Redirects 
# stdout to text file.
echo -e "\n*** RUN 1 - PROGRAM: 1_lab2_1 - 0ms DELAY ***\n" > 3_run1.txt
./1_lab2_1 0 >> 3_run1.txt

echo -e "\n*** RUN 1 - PROGRAM: 1_lab2_1 - 3000ms DELAY ***\n" > 3_run1.txt
./1_lab2_1 3000 >> 3_run1.txt

echo -e "\n*** RUN 2 - PROGRAM: 1_lab2_1 - 500ms DELAY ***\n" >> 3_run1.txt
./1_lab2_1 500 >> 3_run1.txt

echo -e "\n*** RUN 3 - PROGRAM: 1_lab2_1 - 5000ms DELAY ***\n" >> 3_run1.txt
./1_lab2_1 5000 >> 3_run1.txt

# Runs program 2, outputting to console
echo -e "\n*** Run 1 - Program 4_lab2_2 - 3000ms DELAY ***\n" > 6_run2.txt
./4_lab2_2 3000