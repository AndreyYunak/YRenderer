#pragma once

#include <glad/gl.h>
//#include <GLFW/glfw3.h>
//#include "YRendererCore/Window.hpp"

//struct GLFWwindow;

namespace YRenderer {

    namespace Primitive
    {
        enum primitive_t
        {
            Triangles = GL_TRIANGLES,
            Lines = GL_LINES,
            Points = GL_POINTS,
        };
    }
    
    class VertexArray;

    class gl_Renderer {
    public:

        void DrawArrays(const VertexArray& vao, Primitive::primitive_t mode, GLuint offset, GLuint vertices);
        void DrawElements(const VertexArray& vao, Primitive::primitive_t mode, GLuint offset, GLuint count, GLuint type); //intptr_t offset
        
        
        //static bool init(GLFWwindow* pWindow);
        /*
        static void draw(const VertexArray& vertex_array);
        static void set_clear_color(const float r, const float g, const float b, const float a);
        static void clear();
        static void set_viewport(const unsigned int width, const unsigned int height, const unsigned int left_offset = 0, const unsigned int bottom_offset = 0);
        static void enable_depth_test();
        static void disable_depth_test();

        static const char* get_vendor_str();
        static const char* get_renderer_str();
        static const char* get_version_str();
        */
        //void delete_resources();
    public:
        gl_Renderer();
        
        gl_Renderer(const gl_Renderer&)             = delete;
        gl_Renderer(gl_Renderer&&)                  = delete;
        gl_Renderer& operator=(const gl_Renderer&)  = delete;
        gl_Renderer& operator=(gl_Renderer&&)       = delete;
        
        ~gl_Renderer() {
            //void delete_resources();
        };




    private:
        static void platform_init();
        //static void platform_exit();
       
    };



}
