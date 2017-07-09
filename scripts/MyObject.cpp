// © ${YEAR} Joseph Cameron - All Rights Reserved
// Project: MyProject
// Created on ${DATE}.
#include "MyObject.h"
//std inc
#include <iostream>

using namespace MyProject;
using namespace MyModule;

std::ostream& MyProject::MyModule::operator<<(std::ostream& s, const MyModule::MyObject& a)
{
    s.clear();
    s << "{" 
    << "MyObject's operator<< has not been implemented" 
    << "}";
    return s;

}
