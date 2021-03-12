touch 3_run1.txt

echo -e "\n*** RUN 1 - PROGRAM: 1_lab2_1 - 3000ms DELAY ***\n" > 3_run1.txt
./1_lab2_1 3000 >> 3_run1.txt

echo -e "\n*** RUN 2 - PROGRAM: 1_lab2_1 - 500ms DELAY ***\n" >> 3_run1.txt
./1_lab2_1 500 >> 3_run1.txt

echo -e "\n*** RUN 3 - PROGRAM: 1_lab2_1 - 5000ms DELAY ***\n" >> 3_run1.txt
./1_lab2_1 3000 >> 3_run1.txt

touch 6_run2.txt

echo -e "\n*** Run 1 - Program 4_lab2_2 - 3000ms DELAY ***\n" > 6_run2.txt
./4_lab2_2 3000 >> 6_run2.txt