#include "test.h"

#include "Debug/Logger.h"

#include <iostream>
#include <streambuf>

using namespace GDK;

static constexpr auto TAG = "DebugLogTest";

TEST_START
{ "Log", [&]()
{
    auto *const pRawDeviceStringBuffer = std::clog.rdbuf();    
    
    std::stringstream sstream;
    std::clog.rdbuf(sstream.rdbuf());

    Debug::log(TAG, "Hi", 123, 1.2f, false);
    
    std::clog.rdbuf(pRawDeviceStringBuffer);

    if (sstream.str() == "D/DebugLogTest: Hi1231.20\n") test_succeeded();
}},

{ "Error", [&]()
{
    auto *const pRawDeviceStringBuffer = std::cerr.rdbuf();    
    
    std::stringstream sstream;
    std::cerr.rdbuf(sstream.rdbuf());

    Debug::error(TAG, "Thin" "k", " hard: ", 0.266f, false);
    
    std::cerr.rdbuf(pRawDeviceStringBuffer);

    if (sstream.str() == "E/DebugLogTest: Think hard: 0.2660\n") test_succeeded();
}},

{ "User-defined logger, custom behaviour", [&]()
{
    auto logger = Debug::Logger([](const std::string &aMessage)
    {
        std::cout << "Custom/" << aMessage << std::endl;
    });

    auto *const pRawDeviceStringBuffer = std::cout.rdbuf();    
    
    std::stringstream sstream;
    std::cout.rdbuf(sstream.rdbuf());

    logger.log("qwerty");
    
    std::cout.rdbuf(pRawDeviceStringBuffer);

    if (sstream.str() == "Custom/qwerty\n") test_succeeded();
}},

{ "User-defined logger, default behaviour", [&]()
{
    Debug::Logger logger;

    auto *const pRawDeviceStringBuffer = std::clog.rdbuf();    
    
    std::stringstream sstream;
    std::clog.rdbuf(sstream.rdbuf());

    logger.log("qwerty");
    
    std::clog.rdbuf(pRawDeviceStringBuffer);

    if (sstream.str() == "qwerty\n") test_succeeded();
}},

TEST_END
