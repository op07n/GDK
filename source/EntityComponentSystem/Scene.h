// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENE_H
#define GDK_ECS_SCENE_H

//std inc
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

namespace GDK{namespace ECS{class GameObject;}}
namespace GDK{namespace ECS{class SceneGraph;}}
namespace GDK{namespace ECS{class Component; }}
namespace GDK{namespace Math{class IntVector2;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         A 3D space, contains GameObjects. The capabilities of the scene is defined by SceneGraphs
         */
        class Scene final : public std::enable_shared_from_this<Scene>
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Scene&);
            friend GameObject;
      
        public:
            enum class State
            {
                Active,
                Paused
                
            };
            
        private:
            // Data members
            const std::string m_Name;
            State m_SceneState = State::Active;
            std::vector<std::shared_ptr<SceneGraph>> m_SceneGraphs;
            std::vector<std::shared_ptr<GameObject>> m_GameObjects;
            
            void OnComponentAddedToAGameObject(const std::weak_ptr<Component>&);
            void OnComponentRemovedFromAGameObject(const std::weak_ptr<Component>&);
            
            void OnSceneGraphAdded(const std::weak_ptr<SceneGraph> &aSceneGraph);
            void OnSceneGraphRemoved(const std::weak_ptr<SceneGraph> &aSceneGraphRemoved);
            
            void logError();
            
        public:
            // Accessors
            std::weak_ptr<GameObject> getGameObject(const std::string&);
            std::string getName() const;
            State getSceneState() const;
            
            void setState(const State&);
      
            // Public methods
            template<class T>
            std::weak_ptr<T> getSceneGraph()
            {
                static_assert(std::is_base_of<SceneGraph, T>::value == true, "T must be a kind of SceneGraph");
                
                for(size_t i = 0, s = m_SceneGraphs.size(); i < s ; i++)
                    if (auto ptr = dynamic_cast<T>(m_SceneGraphs[i]))
                        return std::weak_ptr<T>(ptr);
                
                return std::weak_ptr<T>();
                
            }
            
            template<class T>
            std::weak_ptr<SceneGraph> addSceneGraph()
            {
                static_assert(std::is_base_of<SceneGraph, T>::value == true, "T must be a kind of SceneGraph");
                
                auto newT = std::shared_ptr<T>(new T(this));
                
                for (size_t i = 0, s = m_SceneGraphs.size(); i < s; i++)
                    if (std::dynamic_pointer_cast<T>(m_SceneGraphs[i]))
                    {
                        logError();
                        return {};
                            
                    }
                
                m_SceneGraphs.push_back(newT);
                
                return std::weak_ptr<T>(newT);
                
            }
            
            void update();
            void fixedUpdate();
            void draw(const Math::IntVector2& aFrameBufferSize);
            
            std::weak_ptr<GameObject> addGameObject();
      
            // Mutating operators
            Scene& operator=(const Scene&) = delete;
      
            // Constructors, destructors
            Scene(const std::string &aName);
        private:
            Scene() = delete;
            Scene(const Scene&) = delete;
        public:
            Scene(Scene&&) = default;
            ~Scene() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::Scene&);
        
    }

}

#endif /* GDK_ECS_SCENE_H  */
