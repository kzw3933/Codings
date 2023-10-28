project(MapPolynomial)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
  test.cpp
)

add_executable(MapPolynomial ${SOURCES})
target_link_libraries(MapPolynomial MapPolynomialStaticLib ListPolynomialSharedLib)
