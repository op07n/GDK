// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_ECS_AUDIO_LISTENER_H
#define GDK_ECS_AUDIO_LISTENER_H

//gdk inc
#include "EntityComponentSystem/Component.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namesapce ECS
    {
        namespace Listener
        {
            /*!
            No description provided for  component
            */
            class  final : public Component
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Listener::&);
      
                // Data members

            protected:
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;

            public:
                // Accessors
      
                // Public methods

                // Constructors, destructors
                (const std::weak_ptr<GameObject> &a) : Component(a) {};

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Listener::&);

        }

    }

}

#endif /* GDK_ECS_AUDIO_LISTENER_H  */
