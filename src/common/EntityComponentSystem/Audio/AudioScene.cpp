// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "AudioScene.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Audio;

std::ostream& GDK::ECS::Audio::operator<<(std::ostream& s, const GDK::ECS::Audio::AudioScene& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "AudioScene's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void AudioScene::draw(const Math::IntVector2 &aFrameBufferSize)
{


}

void AudioScene::fixedUpdate()
{


}

void AudioScene::update()
{


}

void AudioScene::OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &a)
{


}

void AudioScene::OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &a)
{


}
