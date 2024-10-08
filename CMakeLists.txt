cmake_minimum_required(VERSION 3.28)
project(EngineBase)

set(CMAKE_CXX_STANDARD 20)

### Add Raylib


set(RESOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Textures)

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
        src/Objects/DrawAble.cpp
        src/Objects/DrawAble.h
        src/Controllers/TextureController.cpp
        src/Controllers/TextureController.h
        src/Controllers/ObjectController.cpp
        src/Controllers/ObjectController.h
        src/EngineBase.cpp
        src/include/EngineBase/EngineBase.h

        src/include/EngineBase/KeyBoardKeys.h
        src/Command/Command.cpp
        src/include/EngineBase/Command.h
        src/Command/CommandEnums.h
        src/Controllers/ObjectKeeper.cpp
        src/Controllers/ObjectKeeper.h

)
target_include_directories(EngineBase PUBLIC src/include)
target_include_directories(EngineBase PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC
        raylib
)