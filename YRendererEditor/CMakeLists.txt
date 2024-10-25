cmake_minimum_required(VERSION 3.12)

set(EDITOR_PROJECT_NAME YRendererEditor)

set(shader 
	Shader/shader.vs
	Shader/shader.frag
	Shader/shader1.frag
	Shader/shader1.vs
	Shader/shader_texture.frag
	Shader/shader_texture.vs
	)

set_source_files_properties(${shader} PROPERTIES HEADER_FILE_ONLY TRUE)

add_executable(${EDITOR_PROJECT_NAME}
	src/main.cpp
	${shader}
)

target_link_libraries(${EDITOR_PROJECT_NAME} YRendererCore)
target_compile_features(${EDITOR_PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(
	TARGET ${EDITOR_PROJECT_NAME} POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
			${CMAKE_SOURCE_DIR}/${EDITOR_PROJECT_NAME}/Shader 
			$<TARGET_FILE_DIR:${EDITOR_PROJECT_NAME}>/Shader)