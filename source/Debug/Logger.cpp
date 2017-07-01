#include "Logger.h"
//std inc
#include <iostream>
#include <string>

using namespace GDK;
using namespace Debug;

Logger Logger::s_GDKLogger;
Logger Logger::s_GDKErrorLogger([](const std::string& aMessage){std::cerr << aMessage << std::endl;});

Logger::Logger(const std::function<void(const std::string&)> &aLoggingBehaviourCallback)
: m_LoggingBehaviourCallback((aLoggingBehaviourCallback == nullptr)?[](const std::string& aMessage){std::clog<<aMessage<<std::endl;}:aLoggingBehaviourCallback)
{}
