cmake_minimum_required(VERSION 2.6)

project(gkUtils)
file(GLOB SOURCE *.cpp *.h)
include_directories(${OGREKIT_ZLIB_INCLUDE})
add_library(${PROJECT_NAME} ${SOURCE})
