#!/usr/bin/bash

WORK_DIR="/home/ayanokouji/code/C-C++/Music-Player/"
export CC=clang
export CXX=clang++

cd $WORK_DIR
rm -rf build
mkdir build
cd build
cmake ..
make