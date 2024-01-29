cmake_minimum_required(VERSION 3.12)
project(ckilo C)

# 设置 C 编译选项
set(CMAKE_C_FLAGS "-g -Wall -Wextra -pedantic -std=c99") 

# 添加头文件目录
include_directories(include)

# 查找源文件
file(GLOB SOURCES "src/*.c")

# 生成可执行文件
add_executable(kilo ${SOURCES})