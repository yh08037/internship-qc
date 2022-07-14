cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(internship-qc VERSION 0.1)

file(GLOB_RECURSE QASM_FILES src/qasm-tools/*.cpp)
add_library(qasm STATIC ${QASM_FILES})
target_include_directories(qasm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/qasm-tools)

add_executable(mapping src/main.cpp)
target_link_libraries(mapping PUBLIC qasm)
