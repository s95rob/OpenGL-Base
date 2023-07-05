cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(GL_BASE_SRC_FILES
    GL-Base/src/GLBase.h
    GL-Base/src/GL-Base/Log.h
    GL-Base/src/GL-Base/Application.cpp
    GL-Base/src/GL-Base/Application.h
    GL-Base/src/GL-Base/Window.cpp
    GL-Base/src/GL-Base/Window.h
    GL-Base/src/GL-Base/Shader.cpp
    GL-Base/src/GL-Base/Shader.h
    GL-Base/src/GL-Base/Texture.cpp
    GL-Base/src/GL-Base/Texture.h
    GL-Base/src/GL-Base/TextureCache.cpp
    GL-Base/src/GL-Base/TextureCache.h
    extern/glad-4.6/src/glad.c)

project(OpenGL-Base)

add_library(GL-Base ${GL_BASE_SRC_FILES})

# link glfw
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(extern/glfw)

add_dependencies(GL-Base glfw)
target_include_directories(GL-Base 
    PUBLIC extern/glfw/include
    PUBLIC extern/glad-4.6/include
    PUBLIC extern/glm
    PUBLIC extern/stb)
target_link_directories(GL-Base PUBLIC ${CMAKE_BINARY_DIR}/extern/glfw/src/${CMAKE_CFG_INTDIR})
target_link_libraries(GL-Base PUBLIC glfw3)

include(CMake/examples.cmake)

add_example(Textures)
add_example(VertexColors)

add_executable(GL-Sandbox GL-Sandbox/src/Sandbox.cpp)
add_dependencies(GL-Sandbox GL-Base)
target_link_libraries(GL-Sandbox PUBLIC GL-Base)

# Add startup project to Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GL-Sandbox)