#!/bin/bash

# Get all mangled names from your library
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "calc"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "elec"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "physics"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "algebra"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "stat"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "comms"
nm /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib/libadvcalc.so | grep "mesh"

# Search for specific function
nm /path/to/libadvcalc.so | grep " add"      # Find Add
nm /path/to/libadvcalc.so | grep " sub"      # Find subtract
nm /path/to/libadvcalc.so | grep " mult"     # Find multiply
nm /path/to/libadvcalc.so | grep " div"      # Find divide
nm /path/to/libadvcalc.so | grep " expo"     # Find exponent
nm /path/to/libadvcalc.so | grep " squrt"    # Find square root
nm /path/to/libadvcalc.so | grep " cubrt"    # Find cube root
nm /path/to/libadvcalc.so | grep " fact"     # Find factorial
nm /path/to/libadvcalc.so | grep " log"      # Find logarithm
nm /path/to/libadvcalc.so | grep "degrees_F" # Find C to F
nm /path/to/libadvcalc.so | grep "degrees_C" # Find F to C
nm /path/to/libadvcalc.so | grep "FtoK"      # Find F to K
nm /path/to/libadvcalc.so | grep "CtoK"      # Find C to K

#cd /mnt/Basefiles/CLearn/cpplearn/advcalc/advcalclib

#gnatmake proj.adb \
  #-I./include \
  #-L./src \
  #-ladvcalc \
  #-lstdc++ \
  #-o proj

#./proj