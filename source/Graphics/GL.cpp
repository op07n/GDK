#include "GL.h"
//gdk inc
#include "Color.h"

void glClearColor(const GDK::GFX::Color &aColor)
{
    glClearColor(aColor.r,aColor.g,aColor.b,aColor.a);
    
}
