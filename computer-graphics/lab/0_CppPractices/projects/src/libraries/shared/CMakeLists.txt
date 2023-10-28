set(SOURCES
  PolynomialList.cpp
)

add_library(ListPolynomialSharedLib SHARED ${SOURCES})

install(TARGETS ListPolynomialSharedLib
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
)