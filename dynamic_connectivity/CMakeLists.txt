cmake_minimum_required(VERSION 3.10)
project(dynamic_connectivity)

# Disable in-source builds to prevent source tree corruption.
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
      message(FATAL_ERROR "
              FATAL: In-source builds are not allowed.
              You should create a separate directory for build files.")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(union_find union_find.cc)
add_executable(test_dynamic_connectivity test_dynamic_connectivity.cc)
target_link_libraries(test_dynamic_connectivity union_find)
