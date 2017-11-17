// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#include "MeshManager.h"
//std inc
#include <iostream>
//gdk inc
#include "DefaultResources.h"
#include "Memory/default_ptr.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::MeshManager& a) noexcept
{
    s.clear(); s
    << "{";
    
    size_t i = 0;
    
    for (auto &pair : a.m_Map)
    {
        auto mat4x4 = pair.second;
        s << i << ": " << "{Name: " << pair.first << ", " << "Mesh: " << *pair.second << "}";    
    }
    
    s << "}";
    
    return s;
}

MeshManager::MeshManager() noexcept
: resource_manager(GFX::DefaultResources::getQuad().lock())
{}
