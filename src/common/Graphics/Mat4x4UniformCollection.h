// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-22.
#ifndef GDK_GFX_MAT4X4UNIFORMCOLLECTION_H
#define GDK_GFX_MAT4X4UNIFORMCOLLECTION_H

//gdk inc
#include "UniformCollection.h"
#include "Math/Mat4x4.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace GFX
    {
        /*!
         No description provided for Mat4x4UniformCollection
         */
        class Mat4x4UniformCollection final : public UniformCollection<Math::Mat4x4>
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::Mat4x4UniformCollection&);
      
        public:
            // Public methods
            void bind(const GFXuint &aProgramHandle) noexcept override;
            void unbind(const GFXuint &aProgramHandle) noexcept override;
      
            // Mutating operators
            Mat4x4UniformCollection& operator=(const Mat4x4UniformCollection&) = delete;
      
            // Constructors, destructors
            Mat4x4UniformCollection() noexcept = default;
            Mat4x4UniformCollection(const Mat4x4UniformCollection&) noexcept = delete;
            Mat4x4UniformCollection(Mat4x4UniformCollection&&) noexcept = default;
            ~Mat4x4UniformCollection() noexcept = default;
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::Mat4x4UniformCollection&);
        
    }

}

#endif /* GDK_GFX_MAT4X4UNIFORMCOLLECTION_H  */
