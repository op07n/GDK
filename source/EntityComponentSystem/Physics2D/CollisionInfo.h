// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_PHYSICS2D_COLLISIONINFO_H
#define GDK_PHYSICS2D_COLLISIONINFO_H

//gdk inc
#include "Math/Vector2.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace Physics2D{class Collider;}}

namespace GDK
{
    namespace Physics2D
    {
        /*!
         Carries info about a 2D collision: the parties involved and the position of the incident
         */
        struct CollisionInfo final
        {
            friend std::ostream& operator<< (std::ostream&, const Physics2D::CollisionInfo&);
            
            // Data members
            std::weak_ptr<Collider> mine  = {};
            std::weak_ptr<Collider> other = {};
            Math::Vector2 collisionPoint  = {};
            
            // Mutating operators
            CollisionInfo& operator=(const CollisionInfo&) = delete;
      
            // Constructors, destructors
            CollisionInfo(const std::weak_ptr<Collider> &aMine, const std::weak_ptr<Collider> &aOther, const Math::Vector2 &aCollisionPoint);
            CollisionInfo() = delete;
            CollisionInfo(const CollisionInfo&) = delete;
            CollisionInfo(CollisionInfo&&) = delete;
            ~CollisionInfo() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const Physics2D::CollisionInfo&);
        
    }

}

#endif /* GDK_PHYSICS2D_COLLISIONINFO_H  */
