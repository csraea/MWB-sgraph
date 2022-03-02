cmake_minimum_required(VERSION 3.16.3)
project(mwb-sgraph)
set(CMAKE_CXX_FLAGS "-std=c++14 -g -Wall -pedantic ${CMAKE_CXX_FLAGS}")

add_executable(${PROJECT_NAME} src/main.cpp)
add_subdirectory("src")

target_link_directories(${PROJECT_NAME} PRIVATE
                            "src"
)

target_include_directories(${PROJECT_NAME} PUBLIC
                            "src" 
)

target_link_libraries(${PROJECT_NAME} src)