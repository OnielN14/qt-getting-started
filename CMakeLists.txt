cmake_minimum_required(VERSION 3.25)

project(QtGettingStarted VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
    fmt  
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.0.2
)

FetchContent_MakeAvailable(fmt)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

file(GLOB srcs src/*.h src/*.cpp)

add_executable("${PROJECT_NAME}" main.cpp "${srcs}")

target_link_libraries("${PROJECT_NAME}" PRIVATE 
    fmt::fmt 
    Qt::Widgets
)

if (WIN32)
    add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD 
        COMMAND Qt6::windeployqt
        ARGS $<TARGET_FILE:${PROJECT_NAME}>
    )    
endif (WIN32)
