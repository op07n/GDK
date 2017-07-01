#include "Logger.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Debug;

void defaultLoggingBehaviour(const std::string &aMessage)
{
    std::cout << aMessage << std::endl;
    
}

Logger::Logger(const std::function<void(const std::string&)> &aLoggingBehaviourCallback)
: m_LoggingBehaviourCallback((aLoggingBehaviourCallback == nullptr)?defaultLoggingBehaviour:aLoggingBehaviourCallback)
{}
