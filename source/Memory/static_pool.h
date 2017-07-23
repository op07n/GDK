// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-23.
#ifndef GDK_MEMORY_STATIC_POOL_H
#define GDK_MEMORY_STATIC_POOL_H

//std inc
#include <array>
#include <memory>
#include <functional>

namespace GDK
{
	namespace Memory
	{
		/*!
		 Object pool of a fixed length. When get is called, an object with
         a reference count of 1 (unused outside the pool) is returned. If
         no unused objects exist, a nullptr is returned.
    	 */
        template<typename T, size_t length>
		class static_pool
		{
			// Data members
            std::array<std::shared_ptr<T>,length> m_Pool;
            
		public:
			// Public methods
            /// Try to get an object from the pool, will be null if all objects are in use
            std::shared_ptr<T> get()
            {
                for(int i=0;i<m_Pool.size();i++)
                    if (m_Pool[i].use_count() == 1)
                        return m_Pool[i];
                
                return std::shared_ptr<T>();
                
            }
            
			// Mutating operators
			static_pool& operator=(const static_pool&) = delete;
			
			// Constructors, destructors
            static_pool(const std::function<T()> &aObjectInitializer = [](){return T();})
            {
                for(int i=0; i<length;i++)
                    m_Pool[i]=std::make_shared<T>(aObjectInitializer());
                
            }
			static_pool(const static_pool&) = delete;
			static_pool(static_pool&&) = delete;
			virtual ~static_pool() = default;
			
		};

    }

}

#endif /* GDK_MEMORY_STATIC_POOL_H  */
