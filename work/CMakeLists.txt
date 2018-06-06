cmake_minimum_required(VERSION 3.11.2)

project(work)

message(STATUS "start load boost ========================================")
# BOOST
## 设置个变量控制
SET(BOOST_MIN_VERSION "1.67.0")
## 动态查找
FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} REQUIRED)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error:Boost (version >=${BOOST_MIN_VERSION}) required.\n")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${BOOST_LIBRARY_DIRS}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
## 头文件
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
# .BOOST
message(STATUS "end load boost ========================================")


# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(lib/ext/googletest)

#头文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/include ${PROJECT_SOURCE_DIR}lib/ext/googletest/include)


#库文件 : libtest.a 添加到链接路径中
link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/lib/ext/googletest /usr/local/opt/curl/lib/)

#编译器相关设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output/bin")
set(LIBRARIES pthread)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(CMAKE_CXX_FLAGS   "-lboost_date_time-mt-d") # boost

#源码目录
FILE(GLOB_RECURSE SOURCEFILES ${PROJECT_SOURCE_DIR}/src/utility/*.cpp)
FILE(GLOB_RECURSE TEST_SOURCEFILES ${PROJECT_SOURCE_DIR}/src/test/*.cpp)

add_custom_target(cmake-build-debug)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main/main.cpp ${SOURCEFILES})
add_executable(work_test ${TEST_SOURCEFILES} ${SOURCEFILES})

target_link_libraries(${PROJECT_NAME} gtest ${Boost_LIBRARIES} curl)
target_link_libraries(work_test gtest ${Boost_LIBRARIES} curl)


