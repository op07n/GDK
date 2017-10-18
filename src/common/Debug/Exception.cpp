// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#include "Exception.h"
//std inc
#include <iostream>

using namespace GDK;

Exception::Exception(const std::string &aMessage) noexcept
: std::runtime_error(aMessage)
{}

std::ostream& GDK::operator<<(std::ostream& stream, const Exception& aException) noexcept
{
    stream.clear();
    stream << aException.what();
    return stream;

}
