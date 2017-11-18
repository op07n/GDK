// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_MESHMANAGER_H
#define GDK_GFX_MESHMANAGER_H

//gdk inc
#include "Memory/resource_manager.h"
#include "Graphics/Mesh.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace GFX
    {
        /*!
         Instantiates, destroys and serves Mesh objects to the program
         */
        class MeshManager final : public resource_manager<Mesh>
        {
            friend std::ostream &operator<< (std::ostream &, const GFX::MeshManager &) noexcept;
      
        public:
            // Mutating operators
            MeshManager &operator=(const MeshManager &) = default;
            MeshManager &operator=(MeshManager &&) = default;
      
            // Constructors, destructors
            MeshManager() noexcept;
            MeshManager(const MeshManager &) = default;
            MeshManager(MeshManager &&) = default;
            virtual ~MeshManager() noexcept = default;
        };

        std::ostream &operator<< (std::ostream &, const GFX::MeshManager &) noexcept;
    }
}

#endif /* GDK_GFX_MESHMANAGER_H  */
