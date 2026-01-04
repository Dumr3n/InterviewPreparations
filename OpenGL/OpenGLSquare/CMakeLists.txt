cmake_minimum_required(VERSION 3.10)

project(Square)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(GLAD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../glad/include")
set(STB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
set(GLAD_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../glad/src/glad.c")

add_executable(Square main.cpp ${GLAD_SOURCE})

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./res/")
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC TEXTURES_PATH="./tex/")

target_include_directories(Square PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${GLAD_INCLUDE_DIR}
    ${STB_INCLUDE_DIR}
)

target_link_libraries(Square PRIVATE 
    glfw
    ${OPENGL_LIBRARIES}
)

file(GLOB SHADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.vert"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.frag"
)

add_custom_command(TARGET Square POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/res" 
        "$<TARGET_FILE_DIR:Square>/res"
)

add_custom_command(TARGET Square POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/tex" 
        "$<TARGET_FILE_DIR:Square>/tex"
)

if(APPLE)
    target_link_libraries(Square PRIVATE "-framework CoreFoundation")
endif()