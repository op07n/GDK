// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_GRAPHICSRESOURCE_H
#define GDK_GFX_GRAPHICSRESOURCE_H

//std inc
#include <iosfwd>
#include <string>

namespace GDK
{
	namespace GFX
	{
		/*!
		 GraphicsResource is the base class for all graphics resource classes.
         Used for collections.
    	 */
		class GraphicsResource
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::GraphicsResource&);
            
            // Data members
            std::string m_Name;
		
		public:
            // Accessors
            std::string getName() const;
            void setName(const std::string&);
            
			// Constructors, destructors
			GraphicsResource() = delete;
			virtual ~GraphicsResource() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::GraphicsResource&);
        
	}

}

#endif /* GDK_GFX_GRAPHICSRESOURCE_H  */
