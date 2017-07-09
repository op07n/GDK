// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MODEL_H
#define GDK_GFX_MODEL_H

//gdk inc
#include "ShaderProgram.h"
#include "Mesh.h"
#include "TextureUniformCollection.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK
{
	namespace GFX
	{
		/*!
         Represents an observable 3D object. 
         Contains a Mesh, a set of uniform collections, a shader, animations, a skeleton.
         */
		class Model final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Model&);
            
            // Data members
            std::string m_Name;
            std::shared_ptr<Mesh> m_Mesh;
            std::shared_ptr<ShaderProgram> m_ShaderProgram;
            
            TextureUniformCollection m_Textures;
            // etc...
            
		public:
            // Accessors
            void setTexture(const std::string &aUniformName, const std::shared_ptr<Texture> &aTexture);
            
            // public methods
            void draw();
            
			// Mutating operators
			Model& operator=(const Model&) = delete;
			
			// Constructors, destructors
            Model(const std::string &aName, const std::shared_ptr<Mesh>&, const std::shared_ptr<ShaderProgram>&);
			Model() = delete;
			Model(const Model&) = delete;
			~Model() = default;
			
		};
        
		std::ostream& operator<< (std::ostream&, const GFX::Model&);
        
	}

}

#endif /* GDK_GFX_MODEL_H  */
