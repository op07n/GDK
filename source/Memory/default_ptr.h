// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-07-13.
#ifndef GDK_MEMORY_DEFAULT_PTR_H
#define GDK_MEMORY_DEFAULT_PTR_H

//std inc
#include <memory>

namespace GDK
{
    namespace Memory
    {
        /*! 
         a non-owning smart pointer that returns a default instance of T if the internal weak_ptr returns nullptr.
         The design of default_ptr assumes the pointee of m_Default is guaranteed to be valid during the lifetime of the default_ptr
         instance; It is up to the user of this class to guarantee this is the case.
         */
        template<typename T>
        class default_ptr
        {
            const std::weak_ptr<T> m_WeakPtr;
            T const *m_Default;
            
        public:
            T operator->(void) {return m_WeakPtr.IsNull() ? *m_Default : m_WeakPtr.Get();}
            
            // Instancing rules
            default_ptr(const std::weak_ptr<T>& aWeakPtr,T const *aDefault)
            : m_WeakPtr(aWeakPtr)
            , m_Default(aDefault)
            {}
            
            default_ptr& operator=(const default_ptr&) = default;
            default_ptr(const default_ptr&) = default;
            default_ptr() = delete;
            ~default_ptr() = default;
            
        };
        
    }
    
}

#endif /* GDK_MEMORY_DEFAULT_PTR_H */
