cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

project(thread_example)

# Set Headers
set (HEADERS
  src/vector.h
)

# Set Sources
set(SOURCES
  ${HEADERS}
  src/main.cc
)

# Setup target & link
add_executable(THREAD_EXP ${SOURCES})
install(TARGETS THREAD_EXP)
