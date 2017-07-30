// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_MEMORY_AUTH_VECTOR_H
#define GDK_MEMORY_AUTH_VECTOR_H

//std inc
#include <iosfwd>
#include <vector>
#include <memory>

namespace GDK
{
    namespace Memory
    {
        /*!
         No description provided for auth_vector
         */
        template<typename T>
        class auth_vector final
        {
            using iterator               = typename std::vector<T>::iterator;
            using const_iterator         = typename std::vector<T>::const_iterator;
            using reverse_iterator       = typename std::vector<T>::reverse_iterator;
            using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;
            using size_type              = typename std::vector<T>::size_type;
            using value_type             = typename std::vector<T>::value_type;
            using false_type             = bool;
            
            // Data members
            std::vector<T> m_Vector;
            
        public:
            // Iterators
            iterator begin() noexcept {return m_Vector.begin();}
            const_iterator begin() const noexcept {return m_Vector.begin();}
            iterator end() noexcept {return m_Vector.end();}
            const_iterator end() const noexcept {return m_Vector.end();}
            reverse_iterator rbegin() noexcept {return m_Vector.rbegin();}
            const_reverse_iterator rbegin() const noexcept {return m_Vector.rbegin();}
            const_iterator cbegin() const noexcept {return m_Vector.cbegin();}
            const_iterator cend() const noexcept {return m_Vector.cend();}
            const_reverse_iterator crbegin() const noexcept {return m_Vector.crbegin();}
            const_reverse_iterator crend() const noexcept {return m_Vector.crend();}
            
            // Capacity
            size_type size() const noexcept {return m_Vector.size();}
            size_type max_size() const noexcept {return m_Vector.max_size();}
            void resize (size_type n) {return m_Vector.resize(n);}
            void resize (size_type n, const value_type& val) {return m_Vector.resize(n,val);}
            size_type capacity() const noexcept {m_Vector.capacity();}
            bool empty() const noexcept {return m_Vector.empty();}
            void reserve (size_type n) {m_Vector.reserve(n);}
            void shrink_to_fit(){m_Vector.shrink_to_fit();}
            
            // Mutating operators
            auth_vector& operator=(const auth_vector&) = delete;
            
            // Constructors, destructors
            auth_vector() = default;
            auth_vector(const auth_vector&) = delete;
            auth_vector(auth_vector&&) = default;
            ~auth_vector() = default;
            
        };
        
    }

}

#endif /* GDK_MEMORY_AUTH_VECTOR_H  */
