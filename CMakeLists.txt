cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "DumpOpenCLInfo")
project(${PROJECT_NAME})

set(DEBUG_VERSION "DebugMode")
set(RELEASE_VERSION "ReleaseMode")
set(COMPILE_MODE ${DEBUG_VERSION})
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
set(VERSION_MAJOR 2)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 0)

set(CMAKE_CXX_STANDARD 17)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(ARGPARSE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/argparse/include)
set(JSON_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/json/single_include)
set(OPENCL_WRAPPER_DIR ${PROJECT_SOURCE_DIR}/external/opencl-wrapper)

add_subdirectory(${OPENCL_WRAPPER_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
include_directories(
    ${ARGPARSE_INCLUDE_DIR}
    ${JSON_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE OpenCLWrapper)

