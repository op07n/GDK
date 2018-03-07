#include "test.h"

#include "Memory/default_ptr.h"

using namespace GDK;
using namespace Memory;

using data_type = const std::string;

static inline const default_ptr<data_type> createDefaultPtr(const std::shared_ptr<data_type> &aDefaultValue, const std::shared_ptr<data_type> &aVolatileValue)
{
    return default_ptr<data_type>(aDefaultValue, aVolatileValue);
}

TEST_START
{ "Lock Succeeds", [&]()
{
    const auto sDefaultValue = std::make_shared<data_type>("Default. This is returned when the volitale resource is not available.\n"), 
    sVolatileValue = std::make_shared<data_type>("VolatileValue. This is returned when the resource is still available.\n");

    const auto ptr = createDefaultPtr(sDefaultValue, sVolatileValue);

    if (ptr.lock() == sVolatileValue) test_succeeded();
}},

{ "Lock Fails", [&]()
{
    const auto sDefaultValue = std::make_shared<data_type>("Default. This is returned when the volitale resource is not available.\n"); 

    const auto ptr = [&]()
    {
        const auto sVolatileValue = std::make_shared<data_type>("VolatileValue. This is returned when the resource is still available.\n");

        return createDefaultPtr(sDefaultValue, sVolatileValue);
    }();

    if (ptr.lock() == sDefaultValue) test_succeeded();
}},

{ "Move assignment operator", [&]()
{
    const auto dpFirst = default_ptr<data_type>(std::make_shared<data_type>("1"), std::make_shared<data_type>("2"));
    
    const auto dpSecond = std::move(dpFirst);
    
    test_succeeded();
}},

{ "Copy assignment operator", [&]()
{
    const auto dpFirst = default_ptr<data_type>(std::make_shared<data_type>("1"), std::make_shared<data_type>("2"));

    auto dpSecond = dpFirst;

    if (dpFirst == dpSecond) test_succeeded();
}},

{ "Copy Ctor", [&]()
{
    const auto dpFirst = default_ptr<data_type>(std::make_shared<data_type>("1"), std::make_shared<data_type>("2"));
    
    auto dpSecond(dpFirst);

    if (dpFirst == dpSecond) test_succeeded();
}},

{ "Move Ctor", [&]()
{
    const auto dpFirst = default_ptr<data_type>(
        default_ptr<data_type>(std::make_shared<data_type>("1"), std::make_shared<data_type>("2"))
    );

    test_succeeded();
}},

TEST_END
