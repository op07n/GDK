// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-09.
#ifndef GDK_GFX_UNIFORMCOLLECTION_H
#define GDK_GFX_UNIFORMCOLLECTION_H

//gdk inc
#include "DataTypes.h"
//std inc
#include <iosfwd>
#include <string>
#include <map>

namespace GDK
{
    namespace GFX
    {
        /*!
         UniformCollection is used to supply data to shaderprograms.
         It is a baseclass that manages, binds and unbinds a collection of T to a
         shaderprogram
         */
        template<typename T>
        class UniformCollection
        {
        protected:
            // Data members
            std::map<std::string,T> m_Map = {};
            
        public:
            // Public methods
            void put(const std::string &aName, const T &aItem) noexcept
            {
                m_Map.insert({aName, aItem});
            }
            
            T get(const std::string &aName) const noexcept
            {
                return m_Map.find(aName);
            }
            
            virtual void bind(const GFXuint aProgramHandle) noexcept = 0;
            virtual void unbind(const GFXuint aProgramHandle) noexcept = 0;
            
            // Mutating operators
            UniformCollection &operator=(const UniformCollection &) = delete;
            UniformCollection &operator=(UniformCollection &&) = delete;
      
            // Constructors, destructors
            UniformCollection() noexcept = default;
            UniformCollection(const UniformCollection &) = delete;
            UniformCollection(UniformCollection &&) noexcept = default;
            virtual ~UniformCollection() noexcept = default;
        };
    }
}

#endif /* GDK_GFX_UNIFORMCOLLECTION_H  */
