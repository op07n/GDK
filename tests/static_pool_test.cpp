#include "test.h"

#include "Memory/static_pool.h"

#include <vector>

using namespace GDK;
using namespace Memory;

TEST_START
{ "get: comparing valid pointers", [&]()
{
    auto counter = 0;

    const auto pool = static_pool<int, 2>([&]()
    {
        return int(++counter);
    });

    const auto ptr1 = pool.get(), ptr2 = pool.get();

    if (ptr1 != ptr2) test_succeeded();
}},

{ "get: retrieving a nullptr from exhausted pool", [&]()
{
    const auto pool = static_pool<bool, 1>();

    const auto ptr = pool.get();

    pool.get() ? test_failed() : test_succeeded();
}},

TEST_END
