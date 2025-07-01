cmake_minimum_required(VERSION 3.16)

project(Simple2DGameEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug flags
set(CMAKE_BUILD_TYPE Debug)

# Try to find SFML
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# Source files
add_executable(Simple2DGameEngine
        main.cpp
        # Add other source files here
)

# Link SFML libraries
target_link_libraries(Simple2DGameEngine PRIVATE sfml-graphics sfml-window sfml-system)

# SFML headers
target_include_directories(Simple2DGameEngine PRIVATE ${SFML_INCLUDE_DIR})
