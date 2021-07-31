cmake_minimum_required(VERSION 3.15)

project(openggs VERSION 0.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} )
target_include_directories( ${PROJECT_NAME}
                    PRIVATE
                    ${SDL2_INCLUDE_DIR} 
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_MIXER_INCLUDE_DIR})


add_subdirectory(src)