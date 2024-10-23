cmake_minimum_required(VERSION 3.6.0)

set(PROJECT_NAME MEETING)

project(${PROJECT_NAME} LANGUAGES C CXX)

set(COMPILESDK OFF)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(USE_SOLUTION_FOLDERS ON)
option(GROUP_BY_EXPLORER ON)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")


include_directories(${CMAKE_SOURCE_DIR})



add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

if(MSVC)
    string(REGEX REPLACE "/WX" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "/WX" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(BUILD_TYPE "debug")
  set(CURL_NAME "libcurl-d")
else()
  set(CURL_NAME "libcurl")
  set(BUILD_TYPE "release")
endif()


SET(ENV{PATH} "${CMAKE_PREFIX_PATH}//bin")
########### target for DoryWebRtcDemo

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include(windeployqt)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS WinExtras OpenGL Concurrent Widgets Multimedia MultimediaWidgets Network REQUIRED)


set(QTDEMO_SOURCE
        
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

set(AllFile ${QTDEMO_SOURCE} )



if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_executable(
    MEETING WIN32
    ${AllFile}
  )
else()
  add_executable(
    MEETING
    ${AllFile}
  )
endif()

# 启用VS项目文件夹分类
option(USE_SOLUTION_FOLDERS ON)



windeployqt(${PROJECT_NAME} ${BUILD_TYPE})


if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    #set(CMAKE_CXX_FLAGS_DEBUG "/MTd /WX- /Od /Ob0 /Zi")
    #set(CMAKE_C_FLAGS_DEBUG "/MTd /WX- /Od /Ob0 /Zi")
else()
    add_definitions(-DNDEBUG)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT /WX- /O2 /Ob2 /Zi")
    set(CMAKE_C_FLAGS_RELEASE "/MT /WX- /O2 /Ob2 /Zi")
endif()


