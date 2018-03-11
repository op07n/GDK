# MyProject
![alt tag](http://jfcameron.github.io/Github/GDK/EarlyRender.png "")

## CI Information:
![](https://img.shields.io/badge/platforms-%20MacOS%20|%20Ubuntu%20|%20Win64%20-lightgrey.svg) ![](https://coveralls.io/repos/github/jfcameron/GDK/badge.svg?branch=master)

| VM OS | Compiler | Status | Logs | Builds |
| --- | --- | --- | --- | --- |
| Ubuntu | g++ | ![](https://travis-ci.org/jfcameron/GDK.svg?branch=master) | https://travis-ci.org/jfcameron/GDK | [Linux](https://jfcameron.github.io/GDK/build/linux.zip) |
| Macos | clang++ | ![](https://travis-ci.org/jfcameron/GDK.svg?branch=master) | https://travis-ci.org/jfcameron/GDK | [Macos](https://jfcameron.github.io/GDK/build/osx.zip) |
| Win64 | MSVC | ![](https://ci.appveyor.com/api/projects/status/sxivr8m9r1tjggis/branch/master?svg=true) | https://ci.appveyor.com/project/jfcameron/gdk | [Win64](https://jfcameron.github.io/GDK/build/win64.zip) |

Documentation: https://jfcameron.github.io/GDK/
Coverage: https://coveralls.io/github/jfcameron/GDK

## Description:
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
