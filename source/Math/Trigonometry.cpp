// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-22.
#include "Trigonometry.h"
//std inc
#include <iostream>
#include <math.h>

using namespace GDK;
using namespace Math;

const double Trig::Double::PI = 4*atan(1);
const float  Trig        ::PI = (float)Trig::Double::PI;

double Trig::Double::cos(const double &a){return        ::cos(a);}
float  Trig        ::cos(const float  &a){return (float)::cos(a);}

double Trig::Double::sin(const double &a){return        ::sin(a);}
float  Trig        ::sin(const float  &a){return (float)::sin(a);}

double Trig::Double::abs(const double &a){return a < 0.? a/a : a;}
float  Trig        ::abs(const float  &a){return a < 0.? a/a : a;}
