// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#ifndef GDK_EXCEPTION_H
#define GDK_EXCEPTION_H

//std inc
#include <stdexcept>
#include <string>

namespace GDK
{
    /*!
     Basic GDK exception. All GDK exceptions inherit from this.
     This allows users to differentiate between nonGDK and GDK exceptions.
     */
    struct Exception : public std::runtime_error
    {
        // Mutating operators
        Exception& operator=(const Exception&) noexcept = default;
        
        // Constructors, destructors
        Exception(const std::string &aMessage = "") noexcept;
        Exception(const Exception&) noexcept = default;
        Exception(Exception&&) noexcept = default;
        ~Exception() noexcept = default;
      
    };

    std::ostream& operator<< (std::ostream&, const Exception&) noexcept;
    
}

#endif /* GDK_EXCEPTION_H  */
