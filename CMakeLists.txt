cmake_minimum_required(VERSION 3.10)

project(
    tictactoe
    VERSION 0.1.0
    LANGUAGES CXX
)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)

# Add the source files for the project
add_executable(tictactoe src/main.cpp)

# Add Libraries or dependencies if needed
add_library(${PROJECT_NAME}_lib SHARED
    src/board.cpp
)

# Specify the public include directories for the library
target_include_directories(${PROJECT_NAME}_lib 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the library to the executable
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_NAME}_lib
) 

