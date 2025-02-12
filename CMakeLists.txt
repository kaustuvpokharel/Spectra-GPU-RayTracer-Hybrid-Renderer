cmake_minimum_required(VERSION 3.5)

project(Spectra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

set(VULKAN_SDK /Applications/Development/VulkanSDK/macOS)

add_executable(Spectra main.cpp)

# Include Vulkan and GLFW paths
include_directories(
    ${VULKAN_SDK}/include
    /opt/homebrew/include
    /System/Library/Frameworks/OpenGL.framework/Headers
)

# Specify OpenGL paths
set(OPENGL_INCLUDE_DIR /System/Library/Frameworks/OpenGL.framework/Headers)
set(OPENGL_LIBRARY /System/Library/Frameworks/OpenGL.framework)
include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(Spectra
    ${VULKAN_SDK}/lib/libvulkan.1.dylib
    glfw
    "-framework OpenGL"
)

include(GNUInstallDirs)
install(TARGETS Spectra
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
