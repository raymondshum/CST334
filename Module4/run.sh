#!/bin/bash

make clean
make

./queue_test.o > 3_testrun.txt

rm fifo.txt
touch fifo.txt

for i in {1..15}
do
    cache=$(expr $i \* 100)
    echo -e "****** Cache size: $cache ******" >> fifo.txt
    cat accesses.txt | ./1_fifo.o $cache >> fifo.txt
done