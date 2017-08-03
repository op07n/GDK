// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 02-08-26.
#ifndef GDK_ECS_COMPONENT_ANNOTATIONS_H
#define GDK_ECS_COMPONENT_ANNOTATIONS_H

//gdk inc
//#include "EntityComponentSystem/GameObject.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace ECS{class Component;}}
namespace GDK{namespace ECS{class SceneGraph;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         GameObject::Add will fail if a T already exists in its component list
         */
        class UniqueComponent
        {
            friend Scene;
            
        };
        
        /*!
         Gameobject will silently add a component of type T if one does not already exist in its component list
         */
        template<typename T>
        class RequireComponent
        {
            friend Scene;
            static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of Component");
            
            std::shared_ptr<T> getType(){return std::shared_ptr<T>(new T());}
        };
        
        /*!
         The scene that holds the gameobject at GameObject::Add time will add a scenegraph of type T if one does not
         already exist
         */
        template<typename T>
        class RequireSceneGraph
        {
            friend Scene;
            static_assert(std::is_base_of<SceneGraph, T>::value == true, "T must be a kind of SceneGraph");
            
            std::shared_ptr<T> getType(){return std::shared_ptr<T>(new T());}
            
        };
        
    }

}

#endif /* GDK_ECS_COMPONENT_ANNOTATIONS_H  */
