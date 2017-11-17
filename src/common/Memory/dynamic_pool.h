// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-23.
#ifndef GDK_MEMORY_DYNAMIC_POOL_H
#define GDK_MEMORY_DYNAMIC_POOL_H

//std inc
#include <functional>
#include <memory>
#include <vector>

namespace GDK
{
    namespace Memory
    {
        /*!
         Object pool of variable length. When get is called, an object with
         a reference count of 1 (unused outside the pool) is returned. If
         no unused objects exist, a new instance of T is added to the pool and returned
         */
        template<typename T>
        class dynamic_pool final
        {
            // Data members
            size_t m_InitialPoolSize;
            std::function<T()> m_NewObjectInitializer;
            std::vector<std::shared_ptr<T>> m_Pool;

        public:
            // Public methods
            /// Get an object from the pool
            std::shared_ptr<T> get()
            {
                for(size_t i=0;i<m_Pool.size();i++)
                    if (m_Pool[i].use_count() == 1)
                        return m_Pool[i];
              
                m_Pool.push_back(std::make_shared<T>(m_NewObjectInitializer()));
                return m_Pool.back();
            }
          
            /// Try to reduce poolsize back to its initial size by removing any unused items while current size is > init size
            void trim()
            {
                for(size_t i=0;i<m_Pool.size();i++)
                    if (m_Pool.size() <= m_InitialPoolSize)
                        return;
                    else if (m_Pool[i].use_count() == 1)
                        m_Pool.remove(i);
            }
          
            // Mutating operators
            dynamic_pool& operator=(const dynamic_pool&) = delete;
      
            // Constructors, destructors
            dynamic_pool(const size_t aInitialPoolSize, const std::function<T()> aNewObjectInitializer = [](){return T();})
            : m_InitialPoolSize(aInitialPoolSize)
            , m_NewObjectInitializer(aNewObjectInitializer)
            , m_Pool(aInitialPoolSize, std::make_shared<T>(m_NewObjectInitializer()))
            {}
            
            dynamic_pool(const dynamic_pool&) = delete;
            dynamic_pool(dynamic_pool&&) = delete;
            virtual ~dynamic_pool() noexcept = default;
        };
    }
}

#endif /* GDK_MEMORY_DYNAMIC_POOL_H  */
