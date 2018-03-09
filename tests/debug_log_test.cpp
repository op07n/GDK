#include "test.h"

#include "Debug/Logger.h"

#include <iostream>
#include <streambuf>

using namespace GDK;

static constexpr auto TAG = "DebugLogTest";

TEST_START
{ "Log", [&]()
{
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

    std::cout << "Bla" << std::endl;

    std::string text = buffer.str();

    //std::stringstream buffer;
    //std::cout.rdbuf(buffer.rdbuf());

    //Debug::log(TAG, "This"," is a ","message: ",10.56f);
}},

{ "Error", [&]()
{
    //std::stringstream buffer;
    //std::cout.rdbuf(buffer.rdbuf());

    //Debug::error(TAG, 15,"/",4,": ","blabla...",false);
}},

TEST_END
