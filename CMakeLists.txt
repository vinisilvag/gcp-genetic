cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME gcp-genetic)
set(SOURCE main.cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME} VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(genetic src/main.cpp ${SRC_FILES})

target_include_directories(genetic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)