#!/usr/bin/env bash

if [ -z ${1+x} ]; then echo "arg1 is unset: name of test"; exit 1; fi

mkdir "${1}_test"

cat << EOF > ${1}_test/${1}_test.cpp
#include "test.h"

#include "Path/To/${1}.h"

using namespace NamespaceOfTarget;

TEST_START
{ "Example", [&]()
{
    
}},

TEST_END
EOF
