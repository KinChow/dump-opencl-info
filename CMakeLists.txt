cmake_minimum_required(VERSION 3.20)

set(DEBUG_VERSION "DebugMode")
set(RELEASE_VERSION "ReleaseMode")
set(COMPILE_MODE ${DEBUG_VERSION})
set(PROJECT_NAME "DumpOpenCLInfo")

# debug mode (project name + compile time)
if(${COMPILE_MODE} MATCHES ${DEBUG_VERSION})
    set(USE_RELEASE_MODE 0)
    set(CMAKE_BUILD_TYPE "Debug")
# release mode (project name + version)
else()
    set(USE_RELEASE_MODE 1)
    set(CMAKE_BUILD_TYPE "Release")
endif()

string(TIMESTAMP COMPILE_TIME %y%m%d_%H%M%S)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 2)
set(VERSION_TWEAK 0)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(EXTERNAL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external)
set(LIB_LOADER_DIR external/lib_loader)

add_subdirectory(${PROJECT_SOURCE_DIR}/${LIB_LOADER_DIR})

include_directories(
    ${EXTERNAL_INCLUDE_DIR}
    ${PROJECT_BINARY_DIR}/${LIB_LOADER_DIR}/output
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
)

link_directories(
    ${PROJECT_BINARY_DIR}/${LIB_LOADER_DIR}/output
)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)

add_executable(${PROJECT_NAME} ${SRC_DIR})

target_link_libraries(${PROJECT_NAME} LibLoader)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
