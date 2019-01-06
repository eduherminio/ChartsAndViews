#!/bin/bash
clear
set -e
./dos2unix.sh
export env_filename=ChartsAndViews
n_cores=`cat /proc/cpuinfo | grep processor | wc -l`
let "n_cores++"
mkdir -p build && cd build
cmake ..
make -j$n_cores -b
make ChartsAndViews.s

./$env_filename
