cmake_minimum_required(VERSION 3.28)
project(EngineBase)

set(CMAKE_CXX_STANDARD 20)

### Add Raylib

set(RESOURCE_FOLDER ${CMAKE_SOURCE_DIR}/dependencies/EngineBase/Textures)

# Copy the resource folder
file(COPY ${RESOURCE_FOLDER} DESTINATION ${CMAKE_BINARY_DIR})

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


add_library(EngineBase
        src/Controllers/TextureController.cpp
        src/Components/BaseFiles/ObjectFiles/DrawAbleObject.cpp
        src/Controllers/ObjectController.cpp
        src/Components/BaseFiles/Button.cpp
        src/Components/BaseFiles/ShapesPointChecker.cpp
        src/Controllers/EngineBase.cpp
        src/Components/BaseFiles/ObjectFiles/Object.cpp
        src/Components/BaseFiles/ObjectFiles/Visibility.cpp
        src/Components/BaseFiles/ObjectFiles/DragAble.cpp
        src/Components/BaseFiles/ObjectFiles/SceneManager.cpp
        src/Components/BaseFiles/ObjectFiles/ConnectionManager.cpp
        src/Components/BaseFiles/ObjectFiles/TextureManager.cpp
        src/Components/BaseFiles/OnKeyPress.cpp
        src/Components/BaseFiles/HotKeyManager.cpp
        src/Components/TextureToLoad.cpp
        src/Components/TextureToLoad.h
        src/Components/HexColorToLoad.cpp
        src/Components/HexColorToLoad.h
        src/Components/BaseFiles/ObjectFiles/CollisionManager.cpp
        src/Components/BaseFiles/ObjectFiles/CollisionManager.h
)
target_include_directories(EngineBase PUBLIC src/include)
target_include_directories(EngineBase PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC
        raylib
        Utility
)