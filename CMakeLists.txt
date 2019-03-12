cmake_minimum_required(VERSION 3.0)
project(ECS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/ECS/include)
add_subdirectory(ECS)

set(SOURCES main.cpp)

add_executable(ECSDriver ${SOURCES})
target_link_libraries(ECSDriver ECS)

