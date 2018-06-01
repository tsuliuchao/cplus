cmake_minimum_required(VERSION 3.8)

project(work)

message("------------ Options -------------")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("  CMAKE_BUILD_TYPE: Hello World!")

# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(lib/ext/googletest)

#头文件
include_directories(${PROJECT_SOURCE_DIR}/src/include lib/ext/googletest/include)


#库文件 : libtest.a 添加到链接路径中
link_directories(${PROJECT_SOURCE_DIR}/lib lib/ext/googletest)

#编译器相关设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output/bin")
set(LIBRARIES pthread)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告

#源码目录
FILE(GLOB_RECURSE SOURCEFILES ${PROJECT_SOURCE_DIR}/src/utility/*.cpp)
FILE(GLOB_RECURSE TEST_SOURCEFILES ${PROJECT_SOURCE_DIR}/src/test/*.cpp)

add_custom_target(cmake-build-debug)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main/main.cpp ${SOURCEFILES})
add_executable(work_test ${TEST_SOURCEFILES} ${SOURCEFILES})

target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(work_test gtest)


