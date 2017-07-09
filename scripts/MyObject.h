// © 2017 Joseph Cameron - All Rights Reserved
// Project: MyProject
// Created on 17-07-08.
#ifndef MYPROJECT_MYMODULE_MYOBJECT_H
#define MYPROJECT_MYMODULE_MYOBJECT_H

//std inc
#include <iosfwd>

namespace MyProject
{
	namespace MyModule
	{
		/*!
		 No description provided for MyObject
    	 */
		class MyObject
		{
			friend std::ostream& operator<< (std::ostream&, const MyModule::MyObject&);
		
		public:
			// Mutating operators
			MyObject& operator=(const MyObject&) = default;
			
			// Constructors, destructors
			MyObject() = default;
			MyObject(const MyObject&) = default;
			~MyObject() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const MyModule::MyObject&);
        
	}

}

#endif /* MYPROJECT_MYMODULE_MYOBJECT_H  */
