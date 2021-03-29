#!/bin/bash

####################################################################
# Name: Raymond Shum                                               #
# Date: March 30, 2021                                             # 
# Title: Lab 4 - FIFO Page Replacement                             #
# Description: This script makes the fifo and queue_test objects.  #
# It outputs the results of the test run verification (part 3) to  #
# 3_testrun.txt. It then runs the FIFO page replacement program 15 #
# times and outputs the results to fifo.txt.                       #
####################################################################


# Remake objects
make clean
make

# Output test run results
./queue_test.o > 3_testrun.txt

# Remake FIFO results
rm fifo.txt
touch fifo.txt

# Run fifo in increments of 100 from 100 to 1500, inclusive
for i in {1..15}
do
    cache=$(expr $i \* 100)
    echo -e "****** Cache size: $cache ******" >> fifo.txt
    cat accesses.txt | ./1_fifo.o $cache >> fifo.txt
done
