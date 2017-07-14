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
        class default_ptr final
        {
            //Data members
            std::weak_ptr<T> m_WeakPtr;
            T* m_Default;
            
        public:
            // Public methods
            T* get()//default_ptr& operator*()
            {
                if (auto ptr = m_WeakPtr.lock())
                    return ptr.get();
                
                return m_Default;
                
            }
            
            // Mutating operators
            default_ptr& operator=(const default_ptr&) = default;
            
            // Instancing rules
            default_ptr(std::shared_ptr<T>& aWeakPtr,T *aDefault)
            : m_WeakPtr(aWeakPtr)
            , m_Default(aDefault)
            {}
            
            default_ptr() = delete;
            default_ptr(const default_ptr&) = default;
            ~default_ptr() = default;
            
        };
        
    }
    
}

#endif /* GDK_MEMORY_DEFAULT_PTR_H */
