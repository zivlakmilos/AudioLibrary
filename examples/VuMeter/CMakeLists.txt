cmake_minimum_required(VERSION 2.6)
project(vumeter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)

find_package(Qt4 COMPONENTS QtCore QtGui)
find_library(AUDIO_LIBRARY zaudio PATH /usr/local/lib/)

if(NOT AUDIO_LIBRARY)
    message(FATAL_ERROR "ERROR: Can't find zaudio audio library")
endif()

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${QT_INCLUDE}
)

include(${QT_USE_FILE})

set(SRCS
    mainwindow.cpp
    vumeter.cpp
)

set(HEADERS
    mainwindow.cpp
    vumeter.cpp
)

foreach(MOCheader ${HEADERS})
    QT4_WRAP_CPP(MOCsrc ${MOCheader})
endforeach(MOCheader)

add_executable(vumeter main.cpp ${SRCS} ${MOCsrc})
target_link_libraries(vumeter ${QT_LIBRARIES} ${AUDIO_LIBRARY})

install(TARGETS vumeter RUNTIME DESTINATION bin)
