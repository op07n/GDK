// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "AudioScene.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Audio;

static constexpr char TAG[] = "AudioScene";

std::ostream& GDK::ECS::Audio::operator<<(std::ostream& s, const GDK::ECS::Audio::AudioScene& a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

void AudioScene::draw(const Math::IntVector2 &aFrameBufferSize)
{
    (void)aFrameBufferSize;
}

void AudioScene::fixedUpdate()
{

}

void AudioScene::update()
{

}

void AudioScene::OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    (void)a;
}

void AudioScene::OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    (void)a;
}
