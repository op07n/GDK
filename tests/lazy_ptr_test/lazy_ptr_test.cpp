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

{ "struct dereference operator", [&]()
{
    struct data { int val; };
    
    const auto ptr = lazy_ptr<data>([](){return new (data){1};});

    if (ptr->val) test_succeeded();
}},

{ "initialized", [&]()
{
    const auto ptr = lazy_ptr<int>([](){return new int(123);});

    if (!ptr.initialized())
    {
        int &data = *ptr;

        (void)data;

        if (ptr.initialized()) test_succeeded();
    }
}},

TEST_END
