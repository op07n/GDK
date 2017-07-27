// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_GAMEOBJECT_H
#define GDK_ECS_GAMEOBJECT_H

//gkd inc
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
//std inc
#include <iosfwd>
#include <string>
#include <memory>
#include <vector>

namespace GDK{namespace ECS{class Scene;}}
namespace GDK{namespace ECS{class Component;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for GameObject
         */
        class GameObject final
        {
        public:
            struct Transform final
            {
                Math::Vector3    position;
                Math::Vector3    scale;
                Math::Quaternion rotation;
                
                // Mutating operators
                Transform& operator=(const Transform&) = delete;
                
                // Constructors, destructors
                Transform() = delete;
                Transform(const Transform&) = delete;
                Transform(Transform&&) = delete;
                ~Transform() = delete;
                
            }
            
        private:
            friend std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
			
            // Data members
            std::string m_Name;
            std::weak_ptr<Scene> m_MyScene;
            std::vector<std::shared_ptr<Component>> m_Components;
            //Transform m_Transform = new Transform(new WeakReference<>(this));
            
        public:
            // Accessors
            std::string getName();
            std::weak_ptr<Scene> getScene();
            //std::weak_ptr<Transform> getTransform(){return new WeakReference<>(m_Transform);}
            void setName(const std::string &aName);
            
            // Public methods
            size_t getComponentCount(){return m_Components.size();}
            
            std::weak_ptr<Component> getComponent(const int &aIndex){return m_Components[aIndex];}
            
            template<class T>
            std::weak_ptr<Component> addComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                /*
                //Handle RequireComponent & RequireComponents annotations
                {
                    Annotation[] annotations = aComponentType.getAnnotations();
                    
                    for(int i=0,s=annotations.length;i<s;i++)
                        if (annotations[i].annotationType().equals(RequireComponents.class))
                        {
                            RequireComponents rc = (RequireComponents)annotations[i];
                            
                            for(int j=0,t=rc.value().length;j<t;j++)
                                if (getComponent(rc.value()[j])==null)
                                    addComponent(rc.value()[j]);
                                    
                                    }
                        else if (annotations[i].annotationType().equals(RequireComponent.class))
                        {
                            RequireComponent rc = (RequireComponent)annotations[i];
                            
                            if (getComponent(rc.value())==null)
                                addComponent(rc.value());
                                
                                }
                    
                }
                
                //Add an instance of aComponentType to Components[]
                Component rValue = null;
                
                try
                {
                    rValue = aComponentType.newInstance();
                    
                    m_Components.add(rValue);
                    rValue.OnAddedToGameObjectSuper(new WeakReference<>(this));
                    rValue.OnAddedToGameObject(new WeakReference<>(this));
                    
                    m_MyScene.get().OnComponentAdded(rValue);
                    
                    for(int i=0,s=m_Components.size();i<s;i++)
                        m_Components.get(i).OnComponentAdded(rValue);
                        
                        } 
                
                catch (InstantiationException | IllegalAccessException ex) {Logger.getLogger(GameObject.class.getName()).log(Level.SEVERE, null, ex);}
                
                return rValue;*/
                
            }
            
            template<class T>
            void removeComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                /*for (int i=0;i<m_Components.size();i++)
                    if (m_Components.get(i).getClass() == aComponentType)
                    {
                        m_MyScene.get().OnComponentRemoved(m_Components.get(i));
                        
                        for(int j=0,t=m_Components.size();j<t;j++)
                            m_Components.get(j).OnComponentRemoved(m_Components.get(i));
                        
                        m_Components.get(i).OnRemovedFromGameObjectSuper();
                        m_Components.get(i).OnRemovedFromGameObject();
                        m_Components.remove(i);
                        
                    }
                 */
            }
            
            void removeComponent(const std::weak_ptr<Component> aComponentInstance)
            {
                /*for (int i=0;i<m_Components.size();i++)
                    if (m_Components.get(i) == aComponentInstance)
                    {
                        m_MyScene.get().OnComponentRemoved(m_Components.get(i));
                        
                        for(int j=0,t=m_Components.size();j<t;j++)
                            m_Components.get(j).OnComponentRemoved(m_Components.get(i));
                        
                        m_Components.get(i).OnRemovedFromGameObjectSuper();
                        m_Components.get(i).OnRemovedFromGameObject();
                        m_Components.remove(i);
                        
                    }
                */
            }
            
            template<class T>
            public Component getComponent()
            {
               /* Component rValue = null;
                
                Component currentComponent;
                for(int i = 0, s = m_Components.size(); i<s; i++)//m_Components
                {
                    currentComponent = m_Components.get(i);
                    
                    Debug.log(m_Name+": "+aComponentType,currentComponent.getClass());
                    
                    if(aComponentType.isAssignableFrom(currentComponent.getClass()))
                    {
                        rValue = currentComponent;//Debug.log("SUCCESS");
                        
                    }
                    
                }
                
                return rValue; //aComponentType.cast(rValue)*/
                
            }
            
            template<class T>
            public std::vector<Component> getComponents()
            {
                /*ArrayList<Component> rValue = new ArrayList<>();
                
                Component currentComponent;
                for(int i = 0, s = m_Components.size(); i<s; i++)//m_Components
                {
                    currentComponent = m_Components.get(i);
                    
                    if(aComponentType.isAssignableFrom(currentComponent.getClass()))
                        rValue.add(currentComponent);
                    
                }
                
                return rValue;*/
                
            }
            
            public void update()
            {
              /*  Component c;
                for(int i = 0, s = m_Components.size(); i<s; i++ )
                {
                    c = m_Components.get(i);
                    
                    if (!c.getDidInit())
                    {
                        c.initialize();
                        c.setDidinitFalse();
                        
                    }
                    
                    m_Components.get(i).update();
                    
                }
                */
            }
            
            public void fixedUpdate()
            {
               /* Component c = null;
                for(int i = 0, s = m_Components.size(); i<s; i++ )
                {
                    c = m_Components.get(i);
                    
                    if (!c.getDidInit())
                    {
                        c.initialize();
                        c.setDidinitFalse();
                        
                    }
                    
                    m_Components.get(i).fixedUpdate();
                    
                }
             */
            }
			
            // Mutating operators
            GameObject& operator=(const GameObject&) = delete;
			
            // Constructors, destructors
            GameObject(const std::weak_ptr<Scene> &aScene);
            GameObject() = delete;
            GameObject(const GameObject&) = delete;
            GameObject(GameObject&&) = delete;
            ~GameObject() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
        
	}

}

#endif /* GDK_ECS_GAMEOBJECT_H  */
