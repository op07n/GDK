#include "PinkShaderOfDeath.h"
//std inc
#include <string>

using namespace GDK;
using namespace GFX;
using namespace Fallbacks;

/* ============================================== */
/* =========VERTEX SHADER SOURCE================= */
/* ============================================== */
const std::string vertexShaderSource = R"V0G0N(

#version 150
//Uniforms
uniform mat4 _MVP;

//VertIn
in vec3 a_Position;

//VertOut
out vec4 out_Position;

void main ()
{
    out_Position = _MVP * vec4(a_Position,1.0);
    
}

)V0G0N";

/* ============================================== */
/* =========FRAGMENT SHADER SOURCE=============== */
/* ============================================== */
const std::string fragmentShaderSource = R"V0G0N(

#version 150
//FragOut
out vec4 out_Frag;

void main()
{
    out_Frag = vec4(1,0.2,0.8,1);
    
}

)V0G0N";

/*ShaderProgram createPinkShaderOfDeath()
{
    return ShaderProgram("PinkShaderOfDeath",vertexShaderSource,fragmentShaderSource);
    
}*/