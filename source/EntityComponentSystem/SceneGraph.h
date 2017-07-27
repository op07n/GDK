// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENEGRAPH_H
#define GDK_ECS_SCENEGRAPH_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for SceneGraph
         */
        class SceneGraph final
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::SceneGraph&);
			
            // Data members

        public:
            // Accessors
			
            // Public methods
			
            // Mutating operators
            SceneGraph& operator=(const SceneGraph&) = delete;
			
            // Constructors, destructors
            SceneGraph() = delete;
            SceneGraph(const SceneGraph&) = delete;
            SceneGraph(SceneGraph&&) = delete;
            ~SceneGraph() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::SceneGraph&);
        
	}

}

#endif /* GDK_ECS_SCENEGRAPH_H  */
