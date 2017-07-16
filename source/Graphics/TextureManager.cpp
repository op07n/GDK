// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#include "TextureManager.h"
//std inc
#include <iostream>
//gdk inc
#include "DefaultResources.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::TextureManager& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "TextureManager's: " << "operator<< has not been implemented"
    << "}"; return s;

}

TextureManager::TextureManager()
: ResourceManager(new Texture(GFX::DefaultResources::createCheckeredTextureOfDeath()))
{}
