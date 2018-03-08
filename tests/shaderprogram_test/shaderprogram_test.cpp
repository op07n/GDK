#include "test.h"

#include "Graphics/ShaderProgram.h"

using namespace GDK;
using namespace GFX;

constexpr auto VERTEX_SHADER_SOURCE = R"V0G0N(
#version 150
//Uniforms
uniform mat4 _MVP;
    
//VertIn
in vec3 a_Position;
    
void main ()
{
    gl_Position = _MVP * vec4(a_Position,1.0);
}
)V0G0N";

constexpr auto FRAGMENT_SHADER_SOURCE = R"V0G0N(
#version 150
//FragOut
out vec4 out_Frag;
    
void main()
{
    out_Frag = vec4(1,0.2,0.8,1);
}
)V0G0N";

TEST_START
{ "Example", [&]()
{
    //const auto shader = ShaderProgram("MyFancyShader", VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE);
}},

/*
{ "Example", [&]()
{
    
}},
*/

TEST_END
