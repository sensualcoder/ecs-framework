cmake_minimum_required(VERSION 3.0)
project(ECS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")

include_directories(${PROJECT_SOURCE_DIR}/ECS/include)
add_subdirectory(ECS)

if(BUILD_MAC)
    set(CMAKE_CROSSCOMPILING On)
    set(CMAKE_CXX_COMPILER_TARGET "x86_64-apple-darwin-macho")
endif()

if(BUILD_DRIVER)
    include_directories(${PROJECT_SOURCE_DIR}/Driver/include)
    add_subdirectory(Driver)

    set(SOURCES main.cpp)

    add_executable(ECSDriver ${SOURCES})
    target_link_libraries(ECSDriver ECS Driver)
endif()
