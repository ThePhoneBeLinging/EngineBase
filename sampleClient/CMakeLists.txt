cmake_minimum_required(VERSION 3.28)
project(sampleProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(sampleProject
        main.cpp
        SampleObject.cpp
        SampleObject.h
        SampleClient.cpp
        SampleClient.h
)
add_subdirectory(.. EngineBase_build)
target_link_libraries(sampleProject PRIVATE EngineBase)