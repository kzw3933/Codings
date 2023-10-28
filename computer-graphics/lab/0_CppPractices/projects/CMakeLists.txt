cmake_minimum_required(VERSION 3.12)
project(CppPractices)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/libraries/shared)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/libraries/static)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/executables/1_BasicDArray)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/executables/2_EfficientDArray)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/executables/3_TemplateDArray)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/executables/4_ListPolynomial)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/executables/5_MapPolynomial)