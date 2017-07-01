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
        template<typename ...Args> void log(Args && ...args);
        template<typename ...Args> void error(Args && ...args);
        
        /*!
         Used to render debug messages in some form. The default behaviour is to send the data to std::clog,
         however this can be changed by passing a function of sig void(const std::string&) to the constructor. 
         In this way, Logger can be used to print to terminals, buffers, files, etc.
         
         This header also declares the free standing functions Debug::log and Debug::error, which are GDK wrappers for
         std::clog and std::cerr respectively.
         */
        class Logger
        {
            template<typename ...Args> friend void GDK::Debug::log(Args && ...args);
            template<typename ...Args> friend void GDK::Debug::error(Args && ...args);
            
            static Logger s_GDKLogger;
            static Logger s_GDKErrorLogger;
            
            std::function<void(const std::string&)> m_LoggingBehaviourCallback;
            std::ostringstream m_StringBuffer;
            
        public:
            void log() {}
            template<typename First, typename ...Rest>
            void log(First && first, Rest && ...rest)
            {
                m_StringBuffer << first;
                log(std::forward<Rest>(rest)...);
                
                if (sizeof...(Rest) <= 0)
                {
                    m_LoggingBehaviourCallback(m_StringBuffer.str());
                    m_StringBuffer.str(std::string());
                    
                }
                
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
        
        template<typename ...Args>
        void log(Args && ...args)
        {
            Logger::s_GDKLogger.log(std::forward<Args>(args)...);
            
        }
        
        template<typename ...Args>
        void error(Args && ...args)
        {
            Logger::s_GDKErrorLogger.log(std::forward<Args>(args)...);
            
        }
        
    }
    
}

#endif /* GDK_DEBUG_LOGGER_H */
