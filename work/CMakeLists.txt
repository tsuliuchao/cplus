cmake_minimum_required(VERSION 3.8)

project(work)

#头文件
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/include)
#源文件
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/main dir_srcs)
#库文件
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

#编译器相关设置
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-std=c++11")             # c++11
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告

set(WORK ${dir_srcs})

add_executable(work ${WORK})


