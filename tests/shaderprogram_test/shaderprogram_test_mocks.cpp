#include"glew.h"
#include<string>

namespace GLH
{
    std::string GetShaderInfoLog(const GLuint aShaderStageHandle)
    {
        return "GetShaderInfoLog";
    }

    std::string GetProgramInfoLog(const GLuint aShaderProgramHandle)
    {
        return "GetProgramInfoLog";
    }
}