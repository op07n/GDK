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
		 No description provided for ResourceManager
    	 */
        template<typename T>
		class ResourceManager
		{
			// Data members
            std::map<std::string,std::shared_ptr<T>> m_Map;
            std::shared_ptr<T> m_Default;
            
		public:
            // Public methods
            void add(const std::shared_ptr<T> &t)
            {
                m_Map.insert({t->getName(),t});
                
            }
            
            Memory::default_ptr<T> get(const std::string &aName)
            {
                auto it = m_Map.find(aName);
                
                if (it != m_Map.end())
                    return Memory::default_ptr<T>(m_Default,it->second);
                
                return Memory::default_ptr<T>(m_Default);
            
            }
            
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
