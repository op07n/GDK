// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_MESH_H
#define GDK_ECS_GFX_MESH_H

//GDK inc
#include "EntityComponentSystem/Graphics/GraphicsComponent.h"
#include "EntityComponentSystem/Graphics/GraphicsScene.h"
#include "Graphics/Model.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace GFX{class Model;}}
namespace GDK{namespace GFX{class Texture;}}

namespace GDK
{
    namespace ECS
    {
        namespace GFX
        {
            /*!
             ECS abstraction representing 3D graphic representation of a GameObject
            */
            class Mesh final : public GraphicsComponent, public GraphicsScene::Drawable
            {
                friend std::ostream& operator<< (std::ostream&, const ECS::GFX::Mesh&);
                
                GDK::GFX::Model m_Model;
                
            public:
                // Accessors
                void setMesh(const Memory::default_ptr<GDK::GFX::Mesh>&);
                
                void setTexture(const std::string &aUniformName, const Memory::default_ptr<GDK::GFX::Texture> &aTexture);
                void setFloat  (const std::string &aUniformName, const std::shared_ptr<float>                 &aFloat  );
                void setVector2(const std::string &aUniformName, const std::shared_ptr<Math::Vector2>         &aVector2);
                void setVector3(const std::string &aUniformName, const std::shared_ptr<Math::Vector3>         &aVector3);
                void setVector4(const std::string &aUniformName, const std::shared_ptr<Math::Vector4>         &aVector4);
                void setMat4x4 (const std::string &aUniformName, const Math::Mat4x4                           &aMat4x4 );
                
            protected:
                // Drawable interface
                virtual void draw(const std::weak_ptr<Camera> &aCamera) override final;
                // Component interface
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;
                
            public:
                // Constructors, destructors
                Mesh(const std::weak_ptr<GameObject> &aGameObject);
      
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::Mesh&);
            
        }
        
    }

}

#endif /* GDK_ECS_GFX_MESH_H  */
