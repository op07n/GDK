#include "Exception.h"
//std inc
#include <iostream>

using namespace GDK;

Exception::Exception(const std::string &aMessage)
: std::runtime_error(aMessage)
{}

std::ostream& GDK::operator<<(std::ostream& stream, const Exception& aException)
{
    stream.clear();
    stream << aException.what();
    return stream;

}
