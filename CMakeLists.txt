cmake_minimum_required(VERSION 3.15)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()


project(openggs VERSION 0.1)


message("${CMAKE_PROJECT_NAME} version ${CMAKE_PROJECT_VERSION}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

include(FetchContent)

FetchContent_Declare(spdlog 
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.8.5
    GIT_SHALLOW ON 
)

set(SPDLOG_BUILD_SHARED OFF)
set(BUILD_SHARED_LIBS OFF)

FetchContent_MakeAvailable(spdlog)


add_executable(${PROJECT_NAME} )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories( ${PROJECT_NAME}
                    PRIVATE
                    ${SDL2_INCLUDE_DIR} 
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_MIXER_INCLUDE_DIR})


add_subdirectory(src)