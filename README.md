# GDK
![alt tag](http://jfcameron.github.io/Github/GDK/EarlyRender.png "")

## Description:
![asdf](https://img.shields.io/badge/development%20status-active-green.svg)
![asdf](https://img.shields.io/badge/platforms-win32%20|%20osx-lightgrey.svg)
![asdf](https://img.shields.io/badge/license-MIT-blue.svg)

Library for multiplatform game development in C++ (C++11)

### Math
* 2D and 3D linear algebra
* 2-4d Vectors, Quaternion, Mat4x4, Plane

### Graphics
* 3D Rendering via OpenGL
* Multi window support

### Physics2D
* 2D rb sim via Box2D

### Entity Component System
* Organize systems into an ECS

### Input
* Mouse & KB support

### Time, Files, Debug, 3D, Audio

## Building the development kit:
* Add glfw dependency, build GDK, include lib in your project

## Libraries used:
* [GLFW](http://www.glfw.org/) - OpenGL context management, multiplatform window management, time, input utilities.
* [Box2D](https://github.com/erincatto/Box2D) - 2D rigidbody sim
* [stb_image](https://github.com/nothings/stb) - Image decoder
* [GLM](http://glm.g-truc.net/0.9.8/index.html) - Math lib

## Tools used:
* Doxygen
* Python
* CMake
