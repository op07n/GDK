// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#include "MeshManager.h"
//std inc
#include <iostream>
//gdk inc
#include "DefaultResources.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::MeshManager& a)
{
    s.clear(); s << "{";
    int i = 0;
    for (auto &pair : a.m_Map)
    {
        auto mat4x4 = pair.second;
        s << i << ": " << "{Name: " << pair.first << ", " << "Mesh: " << *pair.second << "}";
        
    }
    s << "}"; return s;

}

MeshManager::MeshManager()
: ResourceManager(new Mesh(GFX::DefaultResources::createQuad()))
{}
