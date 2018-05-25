cmake_minimum_required(VERSION 3.8)

project(work)

include_directories(include)

aux_source_directory(src dir_srcs)

set(CMAKE_CXX_STANDARD 11)

set(WORK ${dir_srcs})

add_executable(work ${WORK})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)

