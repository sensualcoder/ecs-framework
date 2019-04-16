cmake_minimum_required(VERSION 3.0)
project(ECS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror -Wno-unused-parameter")

include_directories(${PROJECT_SOURCE_DIR}/ECS/include)
add_subdirectory(ECS)

if(BUILD_DRIVER)
    include_directories(${PROJECT_SOURCE_DIR}/Driver/include)
    add_subdirectory(Driver)

    set(SOURCES main.cpp)

    add_executable(ECSDriver ${SOURCES})
    target_link_libraries(ECSDriver ECS Driver)
endif(BUILD_DRIVER)
