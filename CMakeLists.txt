cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SRC_FILES
    src/Main.cpp
    src/Application.cpp
    src/Application.h
    src/Window.cpp
    src/Window.h
    extern/glad-4.6/src/glad.c)

project(OpenGL-Base)

add_executable(OpenGL-Base ${SRC_FILES})

# link glfw
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(extern/glfw)

add_dependencies(OpenGL-Base glfw)
target_include_directories(OpenGL-Base 
    PUBLIC extern/glfw/include
    PUBLIC extern/glad-4.6/include
    PUBLIC extern/glm)
target_link_directories(OpenGL-Base PUBLIC ${CMAKE_BINARY_DIR}/extern/glfw/src/${CMAKE_CFG_INTDIR})
target_link_libraries(OpenGL-Base glfw3)

# set startup project for visual studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenGL-Base)
set_property(TARGET OpenGL-Base PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/res")