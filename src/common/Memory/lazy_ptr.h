// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2018-03-06.
#ifndef GDK_MEMORY_LAZY_PTR_H
#define GDK_MEMORY_LAZY_PTR_H

//std inc
#include <memory>
#include <functional>

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
        public:
            using InitializerSignature = std::function<T *const ()>;

        private:
            //Data members
            const InitializerSignature m_Initializer;
            mutable std::shared_ptr<T> m_SharedPtr = {};

        public:
            // Public methods
            T *get() const 
            {
                if (!m_SharedPtr)
                    m_SharedPtr.reset(m_Initializer());
                
                return m_SharedPtr.get();
            }

            T &operator*() const
            {
                return *get();
            }

            T *operator->() const
            {
                return get();
            }
            
            // Non-mutating operators
            bool operator== (const lazy_ptr &a) const
            {
                return m_SharedPtr == a.m_SharedPtr;
            }

            // Mutating operators
            lazy_ptr &operator= (const lazy_ptr &a) = default;
            lazy_ptr &operator= (lazy_ptr &&a) = default;
            
            // Instancing rules
            lazy_ptr(const InitializerSignature aInitializer)
            : m_Initializer(aInitializer)
            {}
            
            lazy_ptr() = delete;
            lazy_ptr(const lazy_ptr &) = default;
            lazy_ptr(lazy_ptr &&) = default;
            ~lazy_ptr() = default;
        };
    }
}

#endif /* GDK_MEMORY_LAZY_PTR_H */
