cmake_minimum_required(VERSION 3.5)
project(minidraw)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt5模块
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
message(STATUS "Qt5_DIR: ${Qt5_DIR}")
message(STATUS "Qt5Core_DIR: ${Qt5Core_DIR}")
message(STATUS "Qt5Widgets_DIR: ${Qt5Widgets_DIR}")

# 添加可执行文件
add_executable(minidraw
    src/main.cpp
    src/minidraw.cpp
    src/minidraw.h
    src/minidraw.ui
    src/viewwidget.cpp
    src/viewwidget.h
    src/viewwidget.ui
    src/Shape.cpp
    src/Line.cpp
    src/Rect.cpp
    src/Ellipse.cpp
    src/Polygon.cpp
    src/FreeHand.cpp
)

# 生成对应的头文件
qt5_wrap_ui(UI_HEADERS
    src/minidraw.ui
    src/viewwidget.ui
)

# 添加生成的头文件所在目录
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

# 链接Qt库
target_link_libraries(minidraw Qt5::Core Qt5::Widgets)