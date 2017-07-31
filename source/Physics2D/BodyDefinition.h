// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_PHYSICS2D_BODYDEFINITION_H
#define GDK_PHYSICS2D_BODYDEFINITION_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Physics2D
    {
        /*!
         No description provided for BodyDefinition
         */
        class BodyDefinition final
        {
            friend std::ostream& operator<< (std::ostream&, const Physics2D::BodyDefinition&);
      
            // Data members

        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            BodyDefinition& operator=(const BodyDefinition&) = delete;
      
            // Constructors, destructors
            BodyDefinition() = delete;
            BodyDefinition(const BodyDefinition&) = delete;
            BodyDefinition(BodyDefinition&&) = delete;
            ~BodyDefinition() = delete;
      
        };

        std::ostream& operator<< (std::ostream&, const Physics2D::BodyDefinition&);
        
    }

}

#endif /* GDK_PHYSICS2D_BODYDEFINITION_H  */
