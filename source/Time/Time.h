// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-16.
#ifndef GDK_TIME_TIME_H
#define GDK_TIME_TIME_H

namespace GDK
{
    /*!
     No description provided for Time
     */
	namespace Time
	{
        /// Get time since program started
        double getTime(void);
        /// Get time since update was last called
        double getDeltaTime(void);
        /// Call in the program update loop to get valid deltas
        void update(void);
        
    }
    
}

#endif /* GDK_TIME_TIME_H  */
