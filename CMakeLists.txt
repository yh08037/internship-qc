cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(internship-qc VERSION 0.1)

file(GLOB_RECURSE QASM_FILES src/qasm-tools/*.cpp)
add_library(qasm STATIC ${QASM_FILES})
target_include_directories(qasm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/qasm-tools)

file(GLOB_RECURSE GRAPH_FILES src/coupling-graph/*.cpp)
file(GLOB_RECURSE MAIN_FILES src/main-mapping/*.cpp)
file(GLOB_RECURSE QASM_FILES src/write-qasm/*.cpp)

add_executable(mapping src/main.cpp ${GRAPH_FILES} ${MAIN_FILES} ${QASM_FILES})
target_include_directories(mapping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/coupling-graph)
target_include_directories(mapping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/main-mapping)
target_include_directories(mapping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/write-qasm)
target_link_libraries(mapping PUBLIC qasm stdc++fs)

add_executable(test_graph src/test_graph.cpp ${GRAPH_FILES})
target_include_directories(test_graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/coupling-graph)
target_include_directories(test_graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/main-mapping)
target_include_directories(test_graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/write-qasm)
target_link_libraries(test_graph PUBLIC qasm stdc++fs)
