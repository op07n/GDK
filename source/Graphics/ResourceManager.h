// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_RESOURCEMANAGER_H
#define GDK_GFX_RESOURCEMANAGER_H

//gdk inc
#include "../Memory/default_ptr.h"
#include "../Debug/Exception.h"
//std inc
#include <string>
#include <memory>
#include <map>

namespace GDK
{
	namespace GFX
	{
		/*!
		 A resource manager is responsible for solely managing the lifetime of some object T.
         By serving resources via Memory::default_ptrs, the manager can safely destroy any T instance
         without risking memory reading issues.
    	 */
        template<typename T>
		class ResourceManager
		{
			// Data members
            std::map<std::string,std::shared_ptr<T>> m_Map;
            std::shared_ptr<T> m_Default;
            
		public:
            // Public methods
            Memory::default_ptr<T> get(const std::string &aName)
            {
                auto it = m_Map.find(aName);
                
                if (it != m_Map.end())
                    return Memory::default_ptr<T>(m_Default,it->second);
                
                return Memory::default_ptr<T>(m_Default);
            
            }
            
            void add(const std::shared_ptr<T> &t){m_Map.insert({t->getName(),t});}
			void remove(const std::string &aName){m_Map.erase(aName);}
            void clear(){m_Map.clear();}
            
			// Mutating operators
			ResourceManager& operator=(const ResourceManager&) = default;
			
			// Constructors, destructors
            ResourceManager(T* aDefault)
            : m_Map()
            , m_Default(aDefault)
            {}
            
			ResourceManager() = delete;
			ResourceManager(const ResourceManager&) = default;
			ResourceManager(ResourceManager&&) = default;
			virtual ~ResourceManager() = default;
			
		};
        
	}

}

#endif /* GDK_GFX_RESOURCEMANAGER_H  */
