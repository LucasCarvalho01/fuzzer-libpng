#!/bin/bash -eu

autoreconf -i
./configure
make -j$(nproc)

$CXX $CXXFLAGS -std=c++11 -I/src/include \
    $SRC/libcsv_fuzzer.cc \
    -o $OUT/libcsv_fuzzer \
    $LIB_FUZZING_ENGINE .libs/libcsv.a
    