// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#include "Exception.h"
//std inc
#include <iostream>

using namespace GDK;

std::ostream &GDK::operator<<(std::ostream &stream, const Exception &aException)
{
    stream.clear();
    stream << aException.what();
    return stream;
}
