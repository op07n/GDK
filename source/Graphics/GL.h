// © 2017 Joseph Cameron - &all Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_GL_H
#define GDK_GFX_GL_H

/*!
 OpenGL header for GDK
 includes gl functions from glew and creates useful overloads
 */

//dep inc
#include <glew/include/GL/glew.h>

namespace GDK{namespace GFX{struct Color;}}

void glClearColor(const GDK::GFX::Color &aColor);



#endif /* GDK_GFX_GL_H  */
