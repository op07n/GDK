#include "test.h"

#include <sstream>

#include "Graphics/Color.h"

using namespace GDK;
using namespace GFX;

TEST_START
{ "Default ctor & equality operator", [&]()
{
    const auto color = Color();
    
    if (color == Color::Black) test_succeeded();
}},

{ "operator<<", [&]()
{
    auto sstream = std::stringstream();

    const auto color = Color::Green;

    sstream << color;

    if (sstream.str().size()) test_succeeded();
}},

TEST_END
