#include "test.h"

#include "Memory/dynamic_pool.h"

using namespace GDK;
using namespace Memory;

TEST_START
{ "Get: no grow", [&]()
{
    constexpr size_t INITIAL_SIZE = 1;

    using DataType = int;
    DataType count = 0;

    const auto dynamicPool = dynamic_pool<DataType>(INITIAL_SIZE, [&]()
    {
        return DataType(++count);
    });

    if (const auto ptr = dynamicPool.get() && dynamicPool.size() == INITIAL_SIZE) test_succeeded();
}},

{ "Get: grow", [&]()
{
    constexpr size_t INITIAL_SIZE = 1;

    const auto dynamicPool = dynamic_pool<int>(INITIAL_SIZE, [&]()
    {
        return int(0);
    });

    const auto ptr1 = dynamicPool.get();

    if (const auto ptr2 = dynamicPool.get()) 
    {
        if (dynamicPool.size() > INITIAL_SIZE) test_succeeded();
    }
}},

{ "Trim", [&]()
{
    const auto dynamicPool = dynamic_pool<float>(0, [&]()
    {
        return float(0);
    });

    dynamicPool.get();

    dynamicPool.trim();

    if (dynamicPool.size() == 0) test_succeeded();
}},

TEST_END
