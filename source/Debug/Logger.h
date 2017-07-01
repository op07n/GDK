// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-29.
#ifndef GDK_DEBUG_LOGGER_H
#define GDK_DEBUG_LOGGER_H

//stdlib inc
#include <string>
#include <functional>
#include <sstream>

namespace GDK
{
    namespace Debug
    {
        /*!
         Used to render debug messages in some form. The default behaviour is to send the data to std::cout,
         however this can be changed by passing a function whose signature matches m_LoggingBehaviourCallback
         to the constructor. In this way, Logger can be used to print to terminals, buffers, files, etc.
         */
        class Logger
        {
            std::function<void(const std::string&)> m_LoggingBehaviourCallback;
            
            void concatLog() {}
            template<typename First, typename ...Rest>
            void concatLog(std::ostringstream& s, First && first, Rest && ...rest)
            {
                s << first;
                
                if (sizeof...(Rest) <= 0)
                    m_LoggingBehaviourCallback(s.str());
                
            }
            
        public:
            void log() {}
            
            template<typename First>
            void log(First && first)
            {
                std::ostringstream s;
                s << first;
                m_LoggingBehaviourCallback(s.str());
                
            }
            
            template<typename First, typename ...Rest>
            void log(First && first, Rest && ...rest)
            {
                std::ostringstream s;
                s << first;
                
                concatLog(s,std::forward<Rest>(rest)...);
                
            }
            
            // Mutating operators
            Logger& operator=(const Logger&) = default;
            
            // Constructors & destructors
            /// Change log behavior by passing a function pointer to your own logging function.
            /// Default behaviour is for the logger to display the debug message via std::cout
            Logger(const std::function<void(const std::string&)> &aLoggingBehaviourCallback = nullptr);
            Logger(const Logger&) = default;
            ~Logger() = default;
            
        };
        
    }
    
}

#endif /* GDK_DEBUG_LOGGER_H */
