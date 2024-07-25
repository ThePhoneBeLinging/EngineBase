cmake_minimum_required(VERSION 3.28)
project(EngineBase)

set(CMAKE_CXX_STANDARD 26)

### Add Raylib

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

###
include_directories(Controllers)
include_directories(Components)
include_directories(Components/Shapes)
include_directories(Components/BaseFiles)

add_executable(EngineBase main.cpp
        Controllers/TextureController.cpp
        Components/BaseFiles/DrawAbleObject.cpp
        Controllers/ObjectController.cpp
        Components/BaseFiles/PointCheckerObject.cpp
        Components/Shapes/RectangleObject.cpp
        Components/Shapes/RectangleObject.h
        Components/RectangleButton.cpp
        Components/RectangleButton.h
        Components/BaseFiles/Button.cpp
        Components/BaseFiles/Button.h
)


target_link_libraries(${PROJECT_NAME} raylib)