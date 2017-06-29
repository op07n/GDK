//
//  Debug.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-28.
//
#ifndef GDK_DEBUG_H
#define GDK_DEBUG_H

//stdlib inc
//#include <string>
#include <iostream>
//GDK inc
#include "../Utilities/Macros.h"

namespace GDK
{
    struct Debug
    {
        GDK_UNINSTANTIABLE(Debug);
        
        static void log() {}
        template<typename First, typename ...Rest>
        static void log(First && first, Rest && ...rest)
        {
            std::cout << std::forward<First>(first);
            
            log(std::forward<Rest>(rest)...);
            
            if (sizeof...(Rest) <= 0)
                std::cout << std::endl;
            
        }
        
    };
    
}

#endif /* GDK_DEBUG_H */
