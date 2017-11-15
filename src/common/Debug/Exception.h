// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#ifndef GDK_EXCEPTION_H
#define GDK_EXCEPTION_H

//std inc
#include <stdexcept>
#include <string>
#include <sstream>

namespace GDK
{
    /*!
     Basic GDK exception. All GDK exceptions inherit from this.
     This allows users to differentiate between nonGDK and GDK exceptions.
     */
    class Exception : public std::runtime_error
    {
        std::string toString(std::ostringstream &sstream) noexcept
        {
            return sstream.str();
        }
        
        std::string toString(std::ostringstream &&sstream) noexcept
        {
            return sstream.str();
        }
        
        template<typename First, typename ...Rest>
        std::string toString(std::ostringstream &sstream, First && first, Rest && ...rest) noexcept
        {
            sstream << first;
            toString(sstream, std::forward<Rest>(rest)...);
            return sstream.str();
        }
        
        template<typename First, typename ...Rest>
        std::string toString(std::ostringstream &&sstream, First && first, Rest && ...rest) noexcept
        {
            sstream << first;
            toString(sstream, std::forward<Rest>(rest)...);
            return sstream.str();
        }
        
    public:
        // Mutating operators
        Exception &operator=(const Exception &) noexcept = default;
        Exception &operator=(Exception &&) noexcept = default;
        
        // Constructors, destructors
        template<typename First, typename ...Rest>
        Exception(const char aTag[], First && first, Rest && ...rest) noexcept
        : std::runtime_error(std::string(aTag).append(": ").append([&first]()
        {
            std::ostringstream sstream;
            sstream << first;
            return sstream.str();
        }())
        .append(toString(std::ostringstream(), std::forward<Rest>(rest)...)))
        {}
        
        Exception(const Exception &) noexcept = default;
        Exception(Exception &&) noexcept = default;
        ~Exception() noexcept = default;
    };

    std::ostream &operator<< (std::ostream &, const Exception &) noexcept;
}

#endif /* GDK_EXCEPTION_H  */
