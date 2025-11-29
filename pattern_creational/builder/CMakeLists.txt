cmake_minimum_required(VERSION 3.16)
project(Threads LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Use VCPKG to find the following libs,
# -> FMT (used for general stdout)
find_package(fmt CONFIG REQUIRED)

# Glob Source and Headers
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.cc")
file(GLOB_RECURSE HEADERS "src/*.hpp")

# Setup target & link
add_executable(program ${SOURCES} ${HEADERS})
target_include_directories(program PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(program PRIVATE fmt::fmt)
