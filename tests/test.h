// © 2018 Joseph Cameron - All Rights Reserved
// Project: gdk
// Created on 2018-03-06.

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <utility>

#define test_succeeded()\
[&](){\
    jfc::test::finalstatus = jfc::test::SUCCESS;\
    return;\
}()\

#define test_failed()\
[&](){\
    jfc::test::finalstatus = jfc::test::FAILURE;\
    return;\
}()\

#define TEST_START \
static const char *const FILENAME()\
{\
    static const auto name = []()\
    {\
        auto file = std::string(__FILE__);\
        \
        file.erase(file.begin(), file.begin()+file.find_last_of("/")+1);\
        file.erase(file.begin()+file.find_last_of("."), file.end());\
        \
        return file;\
    }();\
    \
    return name.c_str();\
}\
\
using UnitTest = std::pair<const std::string, const std::function<void()>>;\
\
namespace jfc{ namespace test{\
    constexpr auto SUCCESS = 0, FAILURE = 1;\
    auto finalstatus = FAILURE;\
    auto currentTestName = std::string();\
}}\
\
int main()\
{\
    \
    std::vector<UnitTest> unitTests={
#define TEST_END \
    };\
    \
    for (auto currentTest : unitTests)\
    {\
        jfc::test::finalstatus = jfc::test::FAILURE;\
        \
        jfc::test::currentTestName = std::get<0>(currentTest);\
        \
        try\
        {\
            std::get<1>(currentTest)();\
        }\
        catch(const std::exception& ex)\
        {\
            std::cout << ex.what() << std::endl;\
            \
            jfc::test::finalstatus = jfc::test::FAILURE;\
        }\
        \
        jfc::test::finalstatus == jfc::test::FAILURE ?\
            std::cout << FILENAME() << ": " << jfc::test::currentTestName << ": \033[0;31mfailed!\033[0m\n" :\
            std::cout << FILENAME() << ": " << jfc::test::currentTestName << ": \033[0;32msucceeded!\033[0m\n"\
        ;\
    }\
    \
    return jfc::test::finalstatus;\
}
