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
            
        public:
            void log() {}
            template<typename First, typename ...Rest>
            void log(First && first, Rest && ...rest)
            {
                //TODO: Implement
                std::ostringstream s;
                //s << first;
                
                //for(int i = 0, s =sizeof...(rest); i<s; i++)
                //    s << std::forward<First>(first);
                 
                
                m_LoggingBehaviourCallback(s.str());
                
            }
            
            Logger(const std::function<void(const std::string&)> &aLoggingBehaviourCallback = nullptr);
            
        };
        
    }
    
}

#endif /* GDK_DEBUG_LOGGER_H */
