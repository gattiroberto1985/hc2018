#!/bin/bash

files=""
ofile="bin/hc2018"
for file in $( find . -type f -name "*.c" | grep -v test)
do
    files="$files $file"
done

mkdir -p obj bin
echo "Compiling files: $files . . ."
echo " ----> gcc -g $files -o $ofile <----"
gcc -g $files -o $ofile
