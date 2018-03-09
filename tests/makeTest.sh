#!/usr/bin/env bash

if (( $# > 1 )); then echo "Error: too many args"; exit 1; fi
if [ -z ${1+x} ]; then echo "Error: arg1 is unset: name of test"; exit 1; fi

cat << EOF > ${1}_test.cpp
#include "test.h"

#include "Path/To/${1}.h"

ussing namespace GDK;

TEST_START
{ "Example", [&]()
{
    
}},

TEST_END
EOF
