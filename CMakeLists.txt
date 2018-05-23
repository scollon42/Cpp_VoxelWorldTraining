cmake_minimum_required(VERSION 3.10)
project(Minecraft)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)

file(COPY "${CMAKE_SOURCE_DIR}/data" DESTINATION "${CMAKE_BINARY_DIR}")

include_directories(include)
include_directories(include/Math)
include_directories(include/Renderer)
include_directories(include/Shader)
include_directories(include/State)
include_directories(include/Texture)

add_executable(Minecraft
        include/Math/Matrix.h
        include/Renderer/Master.h
        include/Renderer/SimpleRenderer.h
        include/Shader/Loader.h
        include/Shader/Program.h
        include/Shader/SimpleShader.h
        include/State/Base.h
        include/State/Playing.h
        include/Texture/Atlas.h
        include/Texture/Basic.h
        include/Application.h
        include/Camera.h
        include/Display.h
        include/Entity.h
        include/GLMCommon.h
        include/Model.h
        include/Quad.h
        sources/Math/Matrix.cpp
        sources/Renderer/Master.cpp
        sources/Renderer/SimpleRenderer.cpp
        sources/Shader/Loader.cpp
        sources/Shader/Program.cpp
        sources/Shader/SimpleShader.cpp
        sources/State/Base.cpp
        sources/State/Playing.cpp
        sources/Texture/Atlas.cpp
        sources/Texture/Basic.cpp
        sources/Application.cpp
        sources/Camera.cpp
        sources/Display.cpp
        sources/main.cpp
        sources/Model.cpp
        sources/Quad.cpp include/World/Block/BlockTypes/BlockTypes.h include/World/Block/BlockData.h sources/World/Block/BlockTypes/BlockTypes.cpp include/World/Block/BlockTypes/Grass.h include/World/Block/BlockTypes/Air.h sources/World/Block/BlockTypes/Air.cpp sources/World/Block/BlockTypes/Grass.cpp include/World/Block/BlockID.h include/World/Block/BlockDatabase.h sources/World/Block/BlockDatabase.cpp sources/World/Block/BlockData.cpp sources/World/Block/BockTextures/BlockTexture.cpp include/World/Block/BlockTextures/BlockTexture.h include/Utils/Random.h sources/Utils/Random.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED opengl32 glew32s glu32)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    target_link_libraries(Minecraft ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} GL m dl Xinerama Xrandr Xi Xcursor X11 Xxf86vm pthread)
else()
    message( FATAL_ERROR "NOO OPENGL")
endif()


find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Minecraft ${SFML_LIBRARIES})
else()
    message( FATAL_ERROR "NOOOOOOOOO")
endif()


