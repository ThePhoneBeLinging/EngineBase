cmake_minimum_required(VERSION 3.28)
project(EngineBase)

set(CMAKE_CXX_STANDARD 20)

### Add Raylib

# TODO Add missing texture to this repo and remove this hard coded path
set(RESOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Textures)

# Copy the resource folder
file(COPY ${RESOURCE_FOLDER} DESTINATION ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG4f3c2b1a9d0e8f7c6b5a4d3e2f1a0b9c8d7e6f5a
)

FetchContent_MakeAvailable(raylib)

###


add_library(EngineBase
        src/GraphicsInterface/RayLibImplementation.cpp
        src/EngineBase.cpp
        src/DrawAble.cpp
        src/UpdateController.cpp
        src/CollisionChecker.cpp
        src/include/EngineBase/CollisionChecker.h
        src/Scene/SceneController.cpp
        src/Scene/DrawAbleController.cpp
)

target_include_directories(EngineBase PUBLIC src/include)
target_include_directories(EngineBase PUBLIC src)
target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
)
