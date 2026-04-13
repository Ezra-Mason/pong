#
# Core
#

set(SOURCES
    include/Application.h
    include/Shader.h
    src/Application.cpp
    src/Shader.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})


target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_compile_definitions(Core
    PUBLIC GLFW_INCLUDE_NONE)

target_link_libraries(Core 
    PUBLIC glfw
    PUBLIC glad
)