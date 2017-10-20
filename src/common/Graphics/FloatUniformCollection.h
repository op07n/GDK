// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-09.
#ifndef GDK_GFX_FLOATUNIFORMCOLLECTION_H
#define GDK_GFX_FLOATUNIFORMCOLLECTION_H

//gdk inc
#include "UniformCollection.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK
{
    namespace GFX
    {
        /*!
         Manages and supplies float data for shaderprogram consumption
         */
        class FloatUniformCollection final : public UniformCollection<std::shared_ptr<float>>
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::FloatUniformCollection&) noexcept;
      
        public:
            // Public methods
            void bind(const GFXuint &aProgramHandle) noexcept override;
            void unbind(const GFXuint &aProgramHandle) noexcept override;
            
            // Mutating operators
            FloatUniformCollection& operator=(const FloatUniformCollection&) = delete;
      
            // Constructors, destructors
            FloatUniformCollection() noexcept = default;
            FloatUniformCollection(const FloatUniformCollection&) = delete;
            FloatUniformCollection(FloatUniformCollection&&) = delete;
            ~FloatUniformCollection() noexcept = default;
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::FloatUniformCollection&) noexcept;
        
    }

}

#endif /* GDK_GFX_FLOATUNIFORMCOLLECTION_H  */
