project(ListPolynomial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
  main.cpp
)

add_executable(ListPolynomial ${SOURCES})
target_link_libraries(ListPolynomial ListPolynomialSharedLib)