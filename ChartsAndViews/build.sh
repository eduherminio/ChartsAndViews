#!/bin/bash
clear
# set -e
export env_filename=ChartsAndViews
n_cores=`cat /proc/cpuinfo | grep processor | wc -l`
let "n_cores++"
mkdir -p build && cd build
cmake ..
make -j$n_cores -b

./$env_filename
