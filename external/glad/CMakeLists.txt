cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(glad)

#add_library(glad STATIC include/glad/gl.h src/gl.c)
#target_include_directories(glad PUBLIC ./include/)

set(GLAD_INCLUDES
					"includes/glad/gl.h"
)

set(GLAD_SOURCES
					"src/gl.c"
)

add_library(glad	STATIC
					${GLAD_INCLUDES}
					${GLAD_SOURCES}
)

target_include_directories(glad PUBLIC "includes/")
