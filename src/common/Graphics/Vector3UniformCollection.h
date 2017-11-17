// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-09.
#ifndef GDK_GFX_VECTOR3UNIFORMCOLLECTION_H
#define GDK_GFX_VECTOR3UNIFORMCOLLECTION_H

//gdk inc
#include "UniformCollection.h"
//std inc
#include <iosfwd>

namespace GDK{namespace Math{struct Vector3;}}

namespace GDK
{
    namespace GFX
    {
        /*!
         Manages and supplies Vector3 data for shaderprogram consumption
         */
        class Vector3UniformCollection final : public UniformCollection<std::shared_ptr<Math::Vector3>>
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::Vector3UniformCollection&) noexcept;
      
        public:
            // Public methods
            void bind(const GFXuint aProgramHandle) noexcept override;
            void unbind(const GFXuint aProgramHandle) noexcept override;
            
            // Mutating operators
            Vector3UniformCollection& operator=(const Vector3UniformCollection&) = delete;
      
            // Constructors, destructors
            Vector3UniformCollection() noexcept = default;
            Vector3UniformCollection(const Vector3UniformCollection&) = delete;
            Vector3UniformCollection(Vector3UniformCollection&&) = delete;
            ~Vector3UniformCollection() noexcept = default;
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::Vector3UniformCollection&) noexcept;
        
    }

}

#endif /* GDK_GFX_VECTOR3UNIFORMCOLLECTION_H  */
