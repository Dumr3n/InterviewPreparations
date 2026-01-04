cmake_minimum_required(VERSION 3.10)

project(BlackHole)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(GLEW CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(BlackHole main.cpp)

target_include_directories(BlackHole PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(BlackHole PRIVATE 
    glfw
    ${OPENGL_LIBRARIES}
)

if(APPLE)
    target_link_libraries(BlackHole PRIVATE "-framework CoreFoundation")
endif()