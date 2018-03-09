#include "test.h"

#include "Graphics/Color.h"

using namespace GDK;
using namespace GFX;

TEST_START
{ "Default ctor & equality operator", [&]()
{
    const auto color = Color();
    
    if (color == Color::Black) test_succeeded();
}},

/*
{ "Example", [&]()
{
    
}},
*/

TEST_END
