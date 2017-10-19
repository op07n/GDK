// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_ECS_AUDIO_SOURCE_H
#define GDK_ECS_AUDIO_SOURCE_H

//gdk inc
#include "EntityComponentSystem/Component.h"
#include "Debug/Exception.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        namespace Audio
        {
            /*!
            No description provided for Source component
            */
            class Source final : public Component
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Audio::Source&);
      
                // Data members

            protected:
                // Component interface
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;

            public:
                // Accessors
      
                // Public methods

                // Constructors, destructors
                Source(){throw GDK::Exception("Source", "Source is a stub!");}

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Audio::Source&);

        }

    }

}

#endif /* GDK_ECS_AUDIO_SOURCE_H  */
