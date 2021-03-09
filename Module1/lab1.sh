#!/bin/bash

#########################################
# NAME: Raymond Shum                    #
# CLASS: CST 334                        #
# PROFESSOR: Geri Lamble                #
# TEACHING ASSISTANT: Ibrahim Jabarkhel #
# ASSIGNMENT: Lab 1                     #
# DUE DATE: March 9, 2021               #
#########################################

echo Executing $0
echo $(/bin/ls | wc -l) files

wc -l $(/bin/ls)

echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$

# Sets value of current user and number of active users
user=$(whoami)
numusers=$(who | wc -l)

echo "Hi $user! There are $numusers users logged on."

# Allows program to be used if current user matches "rshum"
if [ $user = "rshum" ]; then
    echo "Now you can proceed!"
else
    echo "Check who logged in!"
    exit 1
fi

# Initialize value of response
response="Yes"

# Asks user for input (heigh, width) and calculates area of
# rectangle until user answers "No"
while [ $response != "No" ]; do
    echo "Enter height of rectangle: "
    read height

    echo "Enter width of rectangle: "
    read width

    area=$(expr $height \* $width)

    echo "The area of the rectangle is $area"
    echo "Would you like to repeat for another rectangle [Yes/No]?"

    read response
done

# Initialize value of response and pi
response="Yes"
pi=3.14

# Asks user for input (radius) and calculates area of circle
# until user answers "No"
while [ $response != "No" ]; do
    echo "Enter the radius of the circle: "
    read radius

    # Variables are piped to the bc program for precision (2 places) calculation
    area=$(echo "scale=2;$pi * $radius * $radius" | bc)

    echo "The area of the circle is $area"
    echo "Would you like to repeat for another circle [Yes/No]?"

    read response
done
