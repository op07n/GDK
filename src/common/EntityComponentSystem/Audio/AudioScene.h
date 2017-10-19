// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_ECS_AUDIO_AUDIOSCENE_H
#define GDK_ECS_AUDIO_AUDIOSCENE_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
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
            No description provided for AudioScene scenegraph
            */
            class AudioScene final : public SceneGraph
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Audio::AudioScene&);
                
                // Data members

            protected:
                // SceneGraph interface
                virtual void draw(const Math::IntVector2 &aFrameBufferSize) override final;
                virtual void fixedUpdate() override final;
                virtual void update()      override final;
                
                virtual void OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component>&)     override final;
                virtual void OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component>&) override final;

            public:
                // Accessors
      
                // Public methods

                // Constructors, destructors
                AudioScene(Scene *a) : SceneGraph(a){throw GDK::Exception("AudioScene", "AudioScene is a stub!");}

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Audio::AudioScene&);

        }

    }

}

#endif /* GDK_ECS_AUDIO_AUDIOSCENE_H  */
