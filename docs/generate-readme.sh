#/bin/usr/env bash

# ===========================
# USER DEFINED README SECTION
# ===========================
SUPPORTED_PLATFORM_LIST=(
    MacOS
    Win64
    Ubuntu
)

PREVIEW_IMAGE_LIST=(
    http://jfcameron.github.io/Github/GDK/EarlyRender.png http://jfcameron.github.io/Github/GDK/EarlyRender.png
)

README=$(cat << README
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

README
)

# ==============
# IMPLEMENTATION
# ==============
GenerateReadme()
{
    GeneratePlatformsBadge()
    {
        local output="![](https://img.shields.io/badge/platforms-"

        for platform in $*; do 
            output+="%20${platform}%20"

            if [ "${platform}" != "${@: -1}" ]; then
                output+="|"
            fi
        done

        echo "${output}-lightgrey.svg)"
    }

    GeneratePreviewImages()
    {
        local output=""

        for ImageURL in $*; do 
            output+="<img src=\"${ImageURL}\" width=\"100%\">"
        done

        echo "${output}"
    }

    # ========================
    # AUTOMATED HEADER SECTION
    # ========================
    local PROJECT_NAME="$(git config --get remote.origin.url | sed -e "s/^https:\/\///" -e "s@.*/@@" -e "s/\..*//")"
    local RELATIVE_PATH_OF_THIS_SCRIPT=$(echo ${PROJECT_NAME}$(echo $(pwd)/${0#"./"} | sed -e "s@.*${PROJECT_NAME}@@"))

    local TRAVIS_CI_BADGE="![](https://travis-ci.org/jfcameron/${PROJECT_NAME}.svg?branch=master)"
    local APPVEYOR_BADGE="![](https://ci.appveyor.com/api/projects/status/github/jfcameron/${PROJECT_NAME})"
    local COVERALLS_BADGE="![](https://coveralls.io/repos/github/jfcameron/${PROJECT_NAME}/badge.svg?branch=master)"

    local TRAVIS_CI_PROJECT_LINK="https://travis-ci.org/jfcameron/${PROJECT_NAME}"
    local APPVEYOR_PROJECT_LINK="https://ci.appveyor.com/project/jfcameron/${PROJECT_NAME}"

    local PLATFORMS_BADGE=$(GeneratePlatformsBadge ${SUPPORTED_PLATFORM_LIST[@]})
    local PREVIEW_IMAGES=$(GeneratePreviewImages ${PREVIEW_IMAGE_LIST[@]})

    cat << OUTPUT > ../README.md
<!--- WARN --->
<!--- This file is automatically generated by ${RELATIVE_PATH_OF_THIS_SCRIPT}. Do not edit directly! --->
<!--- WARN --->
# ${PROJECT_NAME}
${PREVIEW_IMAGES}

## CI Information:
${PLATFORMS_BADGE} ${COVERALLS_BADGE}

| VM OS | Compiler | Status | Logs | Builds |
| --- | --- | --- | --- | --- |
| Ubuntu | g++ | ${TRAVIS_CI_BADGE} | ${TRAVIS_CI_PROJECT_LINK} | [Linux](https://jfcameron.github.io/${PROJECT_NAME}/build/linux.zip) |
| Macos | clang++ | ${TRAVIS_CI_BADGE} | ${TRAVIS_CI_PROJECT_LINK} | [Macos](https://jfcameron.github.io/${PROJECT_NAME}/build/osx.zip) |
| Win64 | MSVC | ${APPVEYOR_BADGE} | ${APPVEYOR_PROJECT_LINK} | [Win64](https://jfcameron.github.io/${PROJECT_NAME}/build/win64.zip) |

| Serivce | URL |
| --- | --- |
| Documentation | https://jfcameron.github.io/${PROJECT_NAME} |
| Coverage | https://coveralls.io/github/jfcameron/${PROJECT_NAME} |

${README}
OUTPUT
    }

GenerateReadme
