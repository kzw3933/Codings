include_directories(${CMAKE_SOURCE_DIR/include})

set(SOURCES
  PolynomialMap.cpp
)

add_library(MapPolynomialStaticLib STATIC ${SOURCES})

install(TARGETS MapPolynomialStaticLib
        ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
)