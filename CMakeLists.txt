cmake_minimum_required(VERSION 3.5)

project(Spectra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

set(VULKAN_SDK /Applications/Development/VulkanSDK/macOS)

######################################################### Define the Vulkan shader compiler
find_program(GLSLC glslc HINTS ${VULKAN_SDK}/bin)

set(SHADER_SOURCE_FILES
    shaders/simple_shader.vert
    shaders/simple_shader.frag
)

set(SHADER_OUTPUT_FILES)
foreach(SHADER IN LISTS SHADER_SOURCE_FILES)
    get_filename_component(SHADER_NAME ${SHADER} NAME)
    set(SPIRV "${CMAKE_BINARY_DIR}/shaders/${SHADER_NAME}.spv")
    add_custom_command(
        OUTPUT ${SPIRV}
        COMMAND ${GLSLC} ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} -o ${SPIRV}
        DEPENDS ${SHADER}
    )
    list(APPEND SHADER_OUTPUT_FILES ${SPIRV})
endforeach()

add_custom_target(Shaders ALL DEPENDS ${SHADER_OUTPUT_FILES})

######################################################### Defined the Vulkan shader compiler

add_executable(Spectra main.cpp
    lve_window.hpp lve_window.cpp
    first_app.hpp first_app.cpp
    shaders/simple_shader.vert
    shaders/simple_shader.frag
    compile.sh
    lve_pipeline.hpp lve_pipeline.cpp
    engine.hpp engine.cpp
)

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
)

include(GNUInstallDirs)
install(TARGETS Spectra
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
