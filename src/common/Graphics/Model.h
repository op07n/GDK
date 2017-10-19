// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MODEL_H
#define GDK_GFX_MODEL_H

//gdk inc
#include "FloatUniformCollection.h"
#include "Mat4x4UniformCollection.h"
#include "Math/Mat4x4.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "TextureUniformCollection.h"
#include "Vector2UniformCollection.h"
#include "Vector3UniformCollection.h"
#include "Vector4UniformCollection.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK {namespace Math{struct Mat4x4;}}
namespace GDK {namespace GFX{class Camera;}}

namespace GDK
{
    namespace GFX
    {
        /*!
         Represents an observable 3D object. 
         Contains a Mesh, a set of uniform collections, a shader, animations, a skeleton.
         */
        class Model final
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::Model&) noexcept;
            
            // Data members
            std::string m_Name = {};
            Math::Mat4x4 m_ModelMatrix = {};
            Memory::default_ptr<Mesh> m_Mesh;
            Memory::default_ptr<ShaderProgram> m_ShaderProgram;
            
            TextureUniformCollection m_Textures = {};
            FloatUniformCollection   m_Floats   = {};
            Vector2UniformCollection m_Vector2s = {};
            Vector3UniformCollection m_Vector3s = {};
            Vector4UniformCollection m_Vector4s = {};
            Mat4x4UniformCollection  m_Mat4x4s  = {};
            
        public:
            // Accessors
            void setMesh(const Memory::default_ptr<Mesh>&) noexcept;
            
            void setTexture(const std::string &aUniformName, const Memory::default_ptr<Texture>   &aTexture) noexcept;
            void setFloat  (const std::string &aUniformName, const std::shared_ptr<float>         &aFloat  ) noexcept;
            void setVector2(const std::string &aUniformName, const std::shared_ptr<Math::Vector2> &aVector2) noexcept;
            void setVector3(const std::string &aUniformName, const std::shared_ptr<Math::Vector3> &aVector3) noexcept;
            void setVector4(const std::string &aUniformName, const std::shared_ptr<Math::Vector4> &aVector4) noexcept;
            void setMat4x4 (const std::string &aUniformName, const Math::Mat4x4                   &aMat4x4 ) noexcept;
            
            const Math::Mat4x4& getModelMatrix() const noexcept;
            void setModelMatrix(const Math::Vector3 &aWorldPos, const Math::Quaternion &aRotation) noexcept;
            
            // public methods
            void draw(const Math::Mat4x4 &aViewMatrix, const Math::Mat4x4 &aProjectionMatrix) noexcept;
            
            // Mutating operators
            Model& operator=(const Model&) = delete;
      
            // Constructors, destructors
            Model(const std::string &aName, const Memory::default_ptr<Mesh>&, const Memory::default_ptr<ShaderProgram>&) noexcept;
            Model() noexcept;
            Model(const Model&) = delete;
            Model(Model&&) = delete;
            ~Model() noexcept = default;
      
        };
        
        std::ostream& operator<< (std::ostream&, const GFX::Model&) noexcept;
        
    }

}

#endif /* GDK_GFX_MODEL_H  */
