// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "DefaultResources.h"
//gdk inc
#include "DataTypes.h"
//std inc
#include <vector>
#include <memory>

using namespace GDK;
using namespace GFX;
using namespace DefaultResources;

namespace
{
    std::shared_ptr<Texture> checkeredTextureOfDeath;
    std::shared_ptr<ShaderProgram> pinkShaderOfDeath;
    std::shared_ptr<ShaderProgram> alphaCutOff;
    std::shared_ptr<Mesh> quad;

}

Memory::default_ptr<Texture> DefaultResources::getCheckeredTextureOfDeath()
{
    if (!checkeredTextureOfDeath)
    {
        std::vector<GFXbyte> textureData(
        {
            0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
            0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08,
            0x08, 0x02, 0x00, 0x00, 0x00, 0x4b, 0x6d, 0x29, 0xdc, 0x00, 0x00, 0x00,
            0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xae, 0xce, 0x1c, 0xe9, 0x00, 0x00,
            0x00, 0x04, 0x67, 0x41, 0x4d, 0x41, 0x00, 0x00, 0xb1, 0x8f, 0x0b, 0xfc,
            0x61, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00,
            0x0e, 0xc3, 0x00, 0x00, 0x0e, 0xc3, 0x01, 0xc7, 0x6f, 0xa8, 0x64, 0x00,
            0x00, 0x00, 0x1b, 0x49, 0x44, 0x41, 0x54, 0x18, 0x57, 0x63, 0xf8, 0xff,
            0xff, 0xff, 0xcc, 0x9b, 0xaf, 0x30, 0x49, 0x06, 0xac, 0xa2, 0x40, 0x72,
            0x30, 0xea, 0xf8, 0xff, 0x1f, 0x00, 0xd3, 0x06, 0xab, 0x21, 0x92, 0xd9,
            0xa4, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42,
            0x60, 0x82
        
        });
        
        ::checkeredTextureOfDeath = std::make_shared<Texture>(GFX::Texture("CheckeredTextureOfDeath",textureData));

    }
    
    return Memory::default_ptr<Texture>(::checkeredTextureOfDeath);
    
}

Memory::default_ptr<ShaderProgram> DefaultResources::getPinkShaderOfDeath()
{
    if (!pinkShaderOfDeath)
    {
        const std::string vertexShaderSource = R"V0G0N(
    
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
    
        const std::string fragmentShaderSource = R"V0G0N(
    
        #version 150
        //FragOut
        out vec4 out_Frag;
    
        void main()
        {
            out_Frag = vec4(1,0.2,0.8,1);
        
        }
    
        )V0G0N";
    
        ::pinkShaderOfDeath = std::make_shared<ShaderProgram>(ShaderProgram("PinkShaderOfDeath",vertexShaderSource,fragmentShaderSource));
    
    }

    return Memory::default_ptr<ShaderProgram>(::pinkShaderOfDeath);
    
}

Memory::default_ptr<ShaderProgram> DefaultResources::getAlphaCutOff()
{
    if (!alphaCutOff)
    {
        const std::string vertexShaderSource = R"V0G0N(
        #version 150
        //Uniforms
        uniform mat4  _MVP;
        uniform mat4  _Model;
        uniform mat4  _View;
        uniform mat4  _Projection;
        uniform float _Time;
        //VertIn
        in vec3 a_Position;
        in vec2 a_UV;
        //VertOut
        out vec2 v_UV;
    
        void main ()
        {
            v_UV = a_UV;
            //gl_Position = _MVP * vec4(a_Position,1.0);
            gl_Position = _Projection * _View * _Model * vec4(a_Position,1.0);
        
        }

        )V0G0N";
    
        const std::string fragmentShaderSource = R"V0G0N(
        #version 150
        //Uniforms
        uniform sampler2D _Texture;
        //FragIn
        in vec2 v_UV;
        //FragOut
        out vec4 out_Frag;
    
        void main()
        {
            vec4 frag = texture(_Texture, v_UV);
            
            if (frag[3] < 1.0)
                discard;
            
            out_Frag = frag;
        
        }

        )V0G0N";
        
        ::alphaCutOff = std::make_shared<ShaderProgram>(ShaderProgram("AlphaCutOff",vertexShaderSource,fragmentShaderSource));
        
    }
    
    return Memory::default_ptr<ShaderProgram>(::alphaCutOff);
    
}

Memory::default_ptr<Mesh> DefaultResources::getQuad()
{
    if (!quad)
    {
        float size = 1.;
        std::vector<GFXfloat> data(
        {
            //           x,              y,    z,    u,    v,
            size -(size/2), size -(size/2), 0.0f, 1.0f, 0.0f, // 1--0
            0.0f -(size/2), size -(size/2), 0.0f, 0.0f, 0.0f, // | /
            0.0f -(size/2), 0.0f -(size/2), 0.0f, 0.0f, 1.0f, // 2
        
            size -(size/2), size -(size/2), 0.0f, 1.0f, 0.0f, //    0
            0.0f -(size/2), 0.0f -(size/2), 0.0f, 0.0f, 1.0f, //  / |
            size -(size/2), 0.0f -(size/2), 0.0f, 1.0f, 1.0f, // 1--2
        
        });
        
        ::quad = std::make_shared<Mesh>(Mesh("Quad",data,VertexFormat::Pos3uv2,Mesh::Type::Static));
        
    }
    
    return Memory::default_ptr<Mesh>(::quad);
    
}
