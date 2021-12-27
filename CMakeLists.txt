cmake_minimum_required(VERSION 3.16)
project(CGFX_LAB5)
find_package(OpenGL REQUIRED)
find_package(SFML COMPONENTS system window graphics REQUIRED)

set(LIBS 
${OPENGL_LIBRARIES} 
sfml-system
sfml-window
sfml-graphics
)
message(STATUS "libs dir: ${LIBS}")
add_executable(gltest openglTest.cpp)
target_link_libraries(gltest ${LIBS})
add_executable(gltest3d opengl3DTest.cpp)
target_link_libraries(gltest3d ${LIBS})