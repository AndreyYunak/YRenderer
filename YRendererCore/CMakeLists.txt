cmake_minimum_required(VERSION 3.12)


set(ENGINE_PROJECT_NAME		YRendererCore)

set(ENGINE_PUBLIC_INCLUDES
							includes/YRendererCore/Application.hpp
							includes/YRendererCore/Event.hpp
)


set(ENGINE_PRIVATE_INCLUDES
							src/YRendererCore/Window.hpp

							src/YRendererCore/gpu/opengl/gl_Renderer.cpp
							src/YRendererCore/gpu/opengl/gl_IndexBuffer.cpp
							src/YRendererCore/gpu/opengl/gl_ShaderProgram.cpp
							src/YRendererCore/gpu/opengl/gl_Texture.cpp
							src/YRendererCore/gpu/opengl/gl_VertexArray.cpp
							src/YRendererCore/gpu/opengl/gl_VertexBuffer.cpp
)
set(ENGINE_PRIVATE_SOURCES
							src/YRendererCore/Application.cpp
							src/YRendererCore/Window.cpp

							src/YRendererCore/gpu/opengl/gl_Renderer.h
							src/YRendererCore/gpu/opengl/gl_IndexBuffer.h
							src/YRendererCore/gpu/opengl/gl_ShaderProgram.h
							src/YRendererCore/gpu/opengl/gl_Texture.h
							src/YRendererCore/gpu/opengl/gl_VertexArray.h
							src/YRendererCore/gpu/opengl/gl_VertexBuffer.h
							src/YRendererCore/gpu/opengl/gl_VertexBufferLayout.h
							src/YRendererCore/gpu/opengl/stb_image.h
)
set(ENGINE_ALL_SOURCES
							${ENGINE_PUBLIC_INCLUDES}
							${ENGINE_PRIVATE_INCLUDES}
							${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} 
			STATIC 
			${ENGINE_ALL_SOURCES}
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} 
			 FILES ${ENGINE_ALL_SOURCES}
)


target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)

target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)



add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)

set(IMGUI_INCLUDES
					../external/imgui/imgui.h
					../external/imgui/backends/imgui_impl_glfw.h
					../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
					../external/imgui/imgui.cpp
					../external/imgui/backends/imgui_impl_glfw.cpp
					../external/imgui/backends/imgui_impl_opengl3.cpp
					../external/imgui/imgui_demo.cpp
					../external/imgui/imgui_tables.cpp
					../external/imgui/imgui_widgets.cpp
					../external/imgui/imgui_draw.cpp
)

add_library(ImGui	STATIC
					${IMGUI_INCLUDES}
					${IMGUI_SOURCES}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE ImGui)