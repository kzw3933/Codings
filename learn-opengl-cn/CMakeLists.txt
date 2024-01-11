cmake_minimum_required(VERSION 3.12)
project(LearnOpenCL)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 添加 glfw 库的包含路径
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# 添加assimp库的包含路径
find_package(assimp REQUIRED)
include_directories(${assimp_INCLUDE_DIRS})

# 添加 include 目录到头文件搜索路径
include_directories(include)

# 添加 .c 文件
file(GLOB C_SOURCES "src/*.c")

# 添加 .cc 文件
file(GLOB CPP_SOURCES "src/*.cc")

# 合并两个源文件列表
set(SOURCES ${C_SOURCES} ${CPP_SOURCES})

# 添加可执行文件
add_executable(app ${SOURCES})

# 链接 glfw 库
target_link_libraries(app glfw3 assimp)