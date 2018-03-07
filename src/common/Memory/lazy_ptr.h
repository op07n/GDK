// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2018-03-06.
#ifndef GDK_MEMORY_LAZY_PTR_H
#define GDK_MEMORY_LAZY_PTR_H

//std inc
#include <memory>

namespace GDK
{
    namespace Memory
    {
        /*! 
         Smart pointer that delays initialization until the first time it is dereferenced
         */
        template<typename T>
        class lazy_ptr final
        {
            //Data members
            std::weak_ptr<T> m_WeakPtr;
            const std::shared_ptr<T> m_Default;
            
        public:
            // Public methods
            std::shared_ptr<T> lock() const 
            {
                if (auto ptr = m_WeakPtr.lock())
                    return ptr;
                
                return m_Default;
            }
            
            // Non-mutating operators
            bool operator== (const lazy_ptr &a) const
            {
                return 
                    m_Default ==        a.m_Default && 
                    m_WeakPtr.lock() == a.m_WeakPtr.lock();
            }

            // Mutating operators
            lazy_ptr &operator= (const lazy_ptr &a) = default;
            lazy_ptr &operator= (lazy_ptr &&a) = default;
            
            // Instancing rules
            lazy_ptr(const std::shared_ptr<T> &aDefault, const std::shared_ptr<T> &aWeakPtr/* = {}*/) 
            : m_WeakPtr(aWeakPtr)
            , m_Default(aDefault)
            {}
            
            lazy_ptr() = delete;
            lazy_ptr(const lazy_ptr &) = default;
            lazy_ptr(lazy_ptr &&) = default;
            ~lazy_ptr() = default;
        };
    }
}

#endif /* GDK_MEMORY_LAZY_PTR_H */
