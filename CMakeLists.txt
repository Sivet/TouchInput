cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

set (CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/ToolchainFile.txt)

project (inputHandling VERSION 1.0)

add_executable(inputHandling 
            main.cpp
            EventCreator.cpp
            Rect.cpp)

target_include_directories(inputHandling 
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

