// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MODEL_H
#define GDK_GFX_MODEL_H

//gdk inc
#include "ShaderProgram.h"
#include "Mesh.h"
#include "TextureUniformCollection.h"
#include "FloatUniformCollection.h"
#include "Vector2UniformCollection.h"
#include "Vector3UniformCollection.h"
#include "Vector4UniformCollection.h"
#include "Mat4x4UniformCollection.h"
#include "Math/Mat4x4.h"
#include "Memory/default_ptr.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK {namespace Math{class Mat4x4;}}
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
            friend std::ostream& operator<< (std::ostream&, const GFX::Model&);
            
            // Data members
            std::string m_Name;
            Math::Mat4x4 m_ModelMatrix;
            Memory::default_ptr<Mesh> m_Mesh;
            Memory::default_ptr<ShaderProgram> m_ShaderProgram;
            
            TextureUniformCollection m_Textures;
            FloatUniformCollection   m_Floats;
            Vector2UniformCollection m_Vector2s;
            Vector3UniformCollection m_Vector3s;
            Vector4UniformCollection m_Vector4s;
            Mat4x4UniformCollection  m_Mat4x4s;
            
        public:
            // Accessors
            void setTexture(const std::string &aUniformName, const Memory::default_ptr<Texture>   &aTexture);
            void setFloat  (const std::string &aUniformName, const std::shared_ptr<float>         &aFloat  );
            void setVector2(const std::string &aUniformName, const std::shared_ptr<Math::Vector2> &aVector2);
            void setVector3(const std::string &aUniformName, const std::shared_ptr<Math::Vector3> &aVector3);
            void setVector4(const std::string &aUniformName, const std::shared_ptr<Math::Vector4> &aVector4);
            void setMat4x4 (const std::string &aUniformName, const Math::Mat4x4                   &aMat4x4 );
            
            const Math::Mat4x4& getModelMatrix() const;
            void setModelMatrix(const Math::Vector3 &aWorldPos, const Math::Quaternion &aRotation);
            
            // public methods
            void draw(const Camera&);
            
            // Mutating operators
            Model& operator=(const Model&) = delete;
      
            // Constructors, destructors
            Model(const std::string &aName, const Memory::default_ptr<Mesh>&, const Memory::default_ptr<ShaderProgram>&);
            Model() = delete;
            Model(const Model&) = delete;
            Model(Model&&) = delete;
            ~Model() = default;
      
        };
        
        std::ostream& operator<< (std::ostream&, const GFX::Model&);
        
    }

}

#endif /* GDK_GFX_MODEL_H  */
