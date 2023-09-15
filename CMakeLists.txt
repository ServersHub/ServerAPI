cmake_minimum_required(VERSION 3.26)
project(AsaApi)

set(CMAKE_CXX_STANDARD 20)

add_library(AsaApi SHARED
        Core/Public/Base.ixx
        Core/Private/Base.cpp
        Core/Public/macro.h
        Core/Public/ASA/GameState.ixx
        stub.cpp)

target_include_directories(AsaApi PUBLIC ${PROJECT_SOURCE_DIR}/Core/Public)

add_definitions(-DARK_EXPORTS)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()