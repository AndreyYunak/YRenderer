cmake_minimum_required(VERSION 3.12)


set(PROJECT_NAME YRenderer)
project(${PROJECT_NAME})



add_subdirectory(YRendererCore)

add_subdirectory(YRendererEditor)



set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT YRendererEditor)