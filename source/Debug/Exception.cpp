#include "Exception.h"
//inc
//...

using namespace GDK;
using namespace Debug;

std::ostream& GDK::Debug::operator<<(std::ostream& stream, const Debug::Exception& aException)
{
    stream.clear();
    stream << "{" << "UNIMPLEMENTED" << "}";
    return stream;

}
