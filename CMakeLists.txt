cmake_minimum_required(VERSION 2.8.11)
project(zaudio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRE sdl2)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRE SDL2_mixer)

include_directories(
    include/
    ${SDL2_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS}
)

set(SOURCES
    src/sdl/audioplayersdl.cpp
    src/sdl/audiosamplersdl.cpp
    src/sdl/audiosamplesdl.cpp
    src/sdl/audioloader.cpp
)

set(LIBRARIES
    ${SDL2_LIBRARIES}
    ${SDL2MIXER_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)
#add_library(${PROJECT_NAME} SHARED ${SOURCES}) 
#add_library(${PROJECT_NAME}_static STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

#install(TARGETS ${PROJECT_NAME} DESTINATION lib)
#install(DIRECTORY include/ DESTINATION include)
