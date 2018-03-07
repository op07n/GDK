#include "test.h"

#include "Memory/lazy_ptr.h"

using namespace GDK;
using namespace Memory;

TEST_START
{ "dereference operator", [&]()
{
    const auto ptr = lazy_ptr<int>([](){return new int(1);});

    if (*ptr) test_succeeded();
}},

TEST_END
