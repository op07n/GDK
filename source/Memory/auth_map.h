// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_MEMORY_AUTH_MAP_H
#define GDK_MEMORY_AUTH_MAP_H

//std inc
#include <iosfwd>
#include <map>
#include <memory>

namespace GDK
{
    namespace Memory
    {
        /*!
         Map that strongly owns its data. insertion can only be done via rvalue reference,
         map data can only be accessed via weak_ptr
         */
        template<typename KeyT, typename ValueT>
        class auth_map final
        {
            using iterator               = typename std::map<KeyT, std::shared_ptr<ValueT>>::iterator;
            using const_iterator         = typename std::map<KeyT, std::shared_ptr<ValueT>>::const_iterator;
            using reverse_iterator       = typename std::map<KeyT, std::shared_ptr<ValueT>>::reverse_iterator;
            using const_reverse_iterator = typename std::map<KeyT, std::shared_ptr<ValueT>>::const_reverse_iterator;
            using mapped_type            = typename std::map<KeyT, std::shared_ptr<ValueT>>::mapped_type;
            using key_type               = typename std::map<KeyT, std::shared_ptr<ValueT>>::key_type;
            using value_type             = typename std::map<KeyT, std::shared_ptr<ValueT>>::value_type;
            using mapped_type_weakptr    = typename std::weak_ptr<ValueT>;
            using mapped_type_sharedptr  = typename std::shared_ptr<ValueT>;
            
            // Data members
            std::map<KeyT, mapped_type_sharedptr> m_Map;

        public:
            // Iterators
            iterator               begin()         noexcept {return m_Map.begin();  }
            const_iterator         begin()   const noexcept {return m_Map.begin();  }
            const_iterator         cbegin()  const noexcept {return m_Map.cbegin(); }
            reverse_iterator       rbegin()        noexcept {return m_Map.rbegin(); }
            const_reverse_iterator rbegin()  const noexcept {return m_Map.rbegin(); }
            const_reverse_iterator crbegin() const noexcept {return m_Map.crbegin();}
            
            iterator               end()         noexcept {return m_Map.end();  }
            const_iterator         end()   const noexcept {return m_Map.end();  }
            const_iterator         cend()  const noexcept {return m_Map.cend(); }
            reverse_iterator       rend()        noexcept {return m_Map.rend(); }
            const_reverse_iterator rend()  const noexcept {return m_Map.rend(); }
            const_reverse_iterator crend() const noexcept {return m_Map.crend();}
            
            // Capacity
            bool   empty()    const noexcept {return m_Map.empty();   }
            size_t size()     const noexcept {return m_Map.size();    }
            size_t max_size() const noexcept {return m_Map.max_size();}
            
            // Element access
            mapped_type_weakptr operator[] (const key_type& k) {return mapped_type_weakptr(m_Map[k]);}
            mapped_type_weakptr operator[] (key_type&& k)      {return mapped_type_weakptr(m_Map[k]);}
            
            mapped_type_weakptr&       at (const key_type& k)       {return mapped_type_weakptr(m_Map.at(k));}
            const mapped_type_weakptr& at (const key_type& k) const {return mapped_type_weakptr(m_Map.at(k));}
            
            // Modifiers
            void insert (const KeyT &aKey, ValueT &&aValue) {m_Map.insert({aKey,std::make_shared<ValueT>(std::move(aValue))});}
            void erase (const KeyT &aKey) {m_Map.erase(aKey);}
            void swap (auth_map& x) {m_Map.swap(x.m_Map);}
            void clear() noexcept {m_Map.clear();}
            
            // Mutating operators
            auth_map& operator=(const auth_map&) = delete;
      
            // Constructors, destructors
            auth_map() = default;
            auth_map(const auth_map&) = delete;
            auth_map(auth_map&&) = default;
            ~auth_map() = default;
      
        };
        
    }

}

#endif /* GDK_MEMORY_AUTH_MAP_H  */
