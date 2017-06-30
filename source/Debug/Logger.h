//
//  Debug.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-29.
//
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
