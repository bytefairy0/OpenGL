cmake_minimum_required(VERSION 3.22.1)
project(OpenGLProject)

find_package(glfw3 3.4 REQUIRED)

#file(GLOB SOURCES "src/*.cpp" "src/*.c")

set(ACTIVE_FILE "src/camera/camera_class/camera_class.cpp")

configure_file(src/shaders/shader2.vs ${CMAKE_CURRENT_BINARY_DIR}/shader2.vs COPYONLY)
configure_file(src/shaders/shader2.fs ${CMAKE_CURRENT_BINARY_DIR}/shader2.fs COPYONLY)

configure_file(src/camera/camera.vs ${CMAKE_CURRENT_BINARY_DIR}/camera.vs COPYONLY)
configure_file(src/camera/camera.fs ${CMAKE_CURRENT_BINARY_DIR}/camera.fs COPYONLY)


add_executable(OpenGLApp ${ACTIVE_FILE} src/glad.c src/stb_image.cpp)


target_include_directories(OpenGLApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(OpenGLApp PRIVATE glfw ${CMAKE_DL_LIBS})

find_package(OpenGL REQUIRED)
target_link_libraries(OpenGLApp PRIVATE OpenGL::GL)
