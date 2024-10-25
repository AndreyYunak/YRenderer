#if 0
#pragma once

#include "YRendererCore/Event.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <string>
#include <functional>
#include <iostream>


namespace YRenderer {

    namespace WindowAttribGet
    {
        enum attrib_t
        {
            FOCUSED = GLFW_FOCUSED,
            ICONIFIED = GLFW_ICONIFIED,
            VISIBLE = GLFW_VISIBLE,
            MAXIMIZED = GLFW_MAXIMIZED,
            HOVERED = GLFW_HOVERED,
            FOCUS_ON_SHOW = GLFW_FOCUS_ON_SHOW,
            MOUSE_PASSTHROUGH = GLFW_MOUSE_PASSTHROUGH,
            TRANSPARENT_FRAMEBUFFER = GLFW_TRANSPARENT_FRAMEBUFFER,
            RESIZABLE = GLFW_RESIZABLE,
            DECORATED = GLFW_DECORATED,
            FLOATING = GLFW_FLOATING,
            AUTO_ICONIFY = GLFW_AUTO_ICONIFY,
            DOUBLEBUFFER = GLFW_DOUBLEBUFFER,
            CLIENT_API = GLFW_CLIENT_API,
            CONTEXT_CREATION_API = GLFW_CONTEXT_CREATION_API,
            CONTEXT_VERSION_MAJOR = GLFW_CONTEXT_VERSION_MAJOR,
            CONTEXT_VERSION_MINOR = GLFW_CONTEXT_VERSION_MINOR,
            CONTEXT_REVISION = GLFW_CONTEXT_REVISION,
            CONTEXT_ROBUSTNESS = GLFW_CONTEXT_ROBUSTNESS,
            OPENGL_FORWARD_COMPAT = GLFW_OPENGL_FORWARD_COMPAT,
            CONTEXT_DEBUG = GLFW_CONTEXT_DEBUG,
            OPENGL_PROFILE = GLFW_OPENGL_PROFILE,
            CONTEXT_RELEASE_BEHAVIOR = GLFW_CONTEXT_RELEASE_BEHAVIOR,
            CONTEXT_NO_ERROR = GLFW_CONTEXT_NO_ERROR
        };
    };

    namespace WindowAttribSet
    {
        enum attrib_t
        {
            AUTO_ICONIFY = GLFW_AUTO_ICONIFY,
            RESIZABLE = GLFW_RESIZABLE,
            DECORATED = GLFW_DECORATED,
            FLOATING = GLFW_FLOATING,
            FOCUS_ON_SHOW = GLFW_FOCUS_ON_SHOW,
            MOUSE_PASSTHROUGH = GLFW_MOUSE_PASSTHROUGH
                        
        };
    };

    namespace WindowHints
    {
        enum hint_t
        {
            SRGB_CAPABLE = GLFW_SRGB_CAPABLE,
            SAMPLES = GLFW_SAMPLES,
            STEREO = GLFW_STEREO,
            AUX_BUFFERS = GLFW_AUX_BUFFERS,
            ACCUM_RED_BITS = GLFW_ACCUM_RED_BITS,
            ACCUM_GREEN_BITS = GLFW_ACCUM_GREEN_BITS,
            ACCUM_BLUE_BITS = GLFW_ACCUM_BLUE_BITS,
            ACCUM_ALPHA_BITS = GLFW_ACCUM_ALPHA_BITS,
            STENCIL_BITS = GLFW_STENCIL_BITS,
            DEPTH_BITS = GLFW_DEPTH_BITS,
            ALPHA_BITS = GLFW_ALPHA_BITS,
            BLUE_BITS = GLFW_BLUE_BITS,
            GREEN_BITS = GLFW_GREEN_BITS,
            RED_BITS = GLFW_RED_BITS,
            FOCUSED = GLFW_FOCUSED,
            VISIBLE = GLFW_VISIBLE,
            MAXIMIZED = GLFW_MAXIMIZED, 
            FOCUS_ON_SHOW = GLFW_FOCUS_ON_SHOW,
            MOUSE_PASSTHROUGH = GLFW_MOUSE_PASSTHROUGH,
            TRANSPARENT_FRAMEBUFFER = GLFW_TRANSPARENT_FRAMEBUFFER,
            RESIZABLE = GLFW_RESIZABLE,
            DECORATED = GLFW_DECORATED,
            FLOATING = GLFW_FLOATING,
            AUTO_ICONIFY = GLFW_AUTO_ICONIFY,
            DOUBLEBUFFER = GLFW_DOUBLEBUFFER,
            CLIENT_API = GLFW_CLIENT_API,
            CONTEXT_CREATION_API = GLFW_CONTEXT_CREATION_API,
            CONTEXT_VERSION_MAJOR = GLFW_CONTEXT_VERSION_MAJOR,
            CONTEXT_VERSION_MINOR = GLFW_CONTEXT_VERSION_MINOR,
            CONTEXT_ROBUSTNESS = GLFW_CONTEXT_ROBUSTNESS,
            OPENGL_FORWARD_COMPAT = GLFW_OPENGL_FORWARD_COMPAT,
            CONTEXT_DEBUG = GLFW_CONTEXT_DEBUG,
            OPENGL_PROFILE = GLFW_OPENGL_PROFILE,
            CONTEXT_RELEASE_BEHAVIOR = GLFW_CONTEXT_RELEASE_BEHAVIOR,
            CONTEXT_NO_ERROR = GLFW_CONTEXT_NO_ERROR,
            POSITION_X = GLFW_POSITION_X,
            POSITION_Y = GLFW_POSITION_Y,
            WIN32_KEYBOARD_MENU = GLFW_WIN32_KEYBOARD_MENU,
            WIN32_SHOWDEFAULT = GLFW_WIN32_SHOWDEFAULT,
            COCOA_GRAPHICS_SWITCHING = GLFW_COCOA_GRAPHICS_SWITCHING,
            SCALE_TO_MONITOR = GLFW_SCALE_TO_MONITOR,
            SCALE_FRAMEBUFFER = GLFW_SCALE_FRAMEBUFFER,
            COCOA_RETINA_FRAMEBUFFER = GLFW_COCOA_RETINA_FRAMEBUFFER,
            CENTER_CURSOR = GLFW_CENTER_CURSOR,
            REFRESH_RATE = GLFW_REFRESH_RATE
        };
    }

    namespace WindowHintsString
    {
        enum hint_t
        {
            COCOA_FRAME_NAME = GLFW_COCOA_FRAME_NAME,
            X11_CLASS_NAME = GLFW_X11_CLASS_NAME,
            X11_INSTANCE_NAME = GLFW_X11_INSTANCE_NAME,
            WAYLAND_APP_ID = GLFW_WAYLAND_APP_ID
        };
    };

    class Camera;

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(BaseEvent&)>;
        Window(std::string title, const unsigned int width, const unsigned int height);
        ~Window();

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;

        void on_update_begin();
        void on_update_end();
        unsigned int get_width() const { return m_data.width; }
        unsigned int get_height() const { return m_data.height; }

        void set_event_callback(const EventCallbackFn& callback)
        {
            m_data.eventCallbackFn = callback;
        };

        std::unique_ptr<class gl_Renderer> m_render = nullptr;
        Camera* camera = nullptr;
        static inline int number_of_windows{};
        
    private:
        
        struct WindowData
        {
            std::string title;
            unsigned int width;
            unsigned int height;
            EventCallbackFn eventCallbackFn;
        };

        int init();
        void shutdown();

        GLFWwindow* m_pWindow = nullptr;
        WindowData m_data;
        float m_background_color[4] = { 1.f, 0.f, 0.f, 0.f };


    public:
        int CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL)
        {
            m_pWindow = glfwCreateWindow(width, height, title, monitor, share);
            if (!m_pWindow)
            {
                std::cout << title << ": glfwCreateWindow ERROR" << std::endl;
                glfwTerminate();
                return 1;
            }
            std::cout << title << ": glfwCreateWindow OK!" << std::endl;
            number_of_windows++;

            MakeContextCurrent();

            int version = gladLoadGL(glfwGetProcAddress);
            if (version == 0) {
                std::cout << "Failed to initialize OpenGL context\n";
                // return -1;
            }


            m_render = std::make_unique<gl_Renderer>();

            return 0;
        }
        

        void defaultWindowHints() {
            glfwDefaultWindowHints();
        }
        static void WindowHint(WindowHints::hint_t hint, int value) {
            glfwWindowHint(hint, value);
        }
        void windowHintString(WindowHintsString::hint_t hint, const char* value) {
            glfwWindowHintString(hint, value);
        }
        //void glfwDestroyWindow(GLFWwindow* handle)
        //int glfwWindowShouldClose(GLFWwindow* handle)
        //void glfwSetWindowShouldClose(GLFWwindow* handle, int value)
        const char*  GetWindowTitle(GLFWwindow* handle) {
            return glfwGetWindowTitle(handle); //const char* glfwGetWindowTitle(GLFWwindow* handle)
        }        
        //void glfwSetWindowTitle(GLFWwindow* handle, const char* title)
        //void glfwSetWindowIcon(GLFWwindow* handle, int count, const GLFWimage* images)
        //void glfwGetWindowPos(GLFWwindow* handle, int* xpos, int* ypos)
        //void glfwSetWindowPos(GLFWwindow* handle, int xpos, int ypos)
        //void glfwGetWindowSize(GLFWwindow* handle, int* width, int* height)
        //void glfwSetWindowSize(GLFWwindow* handle, int width, int height)
        //void glfwSetWindowSizeLimits(GLFWwindow* handle, int minwidth, int minheight, int maxwidth, int maxheight)
        //void glfwSetWindowAspectRatio(GLFWwindow* handle, int numer, int denom)
        //void glfwGetWindowFrameSize(GLFWwindow* handle, int* left, int* top, int* right, int* bottom)
        //void glfwGetWindowContentScale(GLFWwindow* handle, float* xscale, float* yscale)
        //float glfwGetWindowOpacity(GLFWwindow* handle)
        //void glfwSetWindowOpacity(GLFWwindow* handle, float opacity)
        //void glfwIconifyWindow(GLFWwindow* handle)
        //void glfwRestoreWindow(GLFWwindow* handle)
        //void glfwMaximizeWindow(GLFWwindow* handle)
        //void glfwShowWindow(GLFWwindow* handle)
        //void glfwRequestWindowAttention(GLFWwindow* handle)
        //void glfwHideWindow(GLFWwindow* handle)
        //void glfwFocusWindow(GLFWwindow* handle)
        int getWindowAttrib(WindowAttribGet::attrib_t attrib) {
            return glfwGetWindowAttrib(m_pWindow, attrib);
        }
        void setWindowAttrib(WindowAttribSet::attrib_t attrib, int value) {
            glfwSetWindowAttrib(m_pWindow, attrib, value);
        }
        
        //GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* handle)
     
        /*void glfwSetWindowMonitor(GLFWwindow* wh,
                                        GLFWmonitor* mh,
                                        int xpos, int ypos,
                                        int width, int height,
                                        int refreshRate)
                                        */
        //void glfwSetWindowUserPointer(GLFWwindow* handle, void* pointer)
        //void* glfwGetWindowUserPointer(GLFWwindow* handle)
        //GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* handle, GLFWwindowposfun cbfun)
        //GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow* handle, GLFWwindowsizefun cbfun)
        //GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* handle, GLFWwindowclosefun cbfun)
        //GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow* handle, GLFWwindowrefreshfun cbfun)
        //GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* handle, GLFWwindowfocusfun cbfun)
        //GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* handle, GLFWwindowiconifyfun cbfun)
        //GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow* handle, GLFWwindowmaximizefun cbfun)
        //GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* handle, GLFWframebuffersizefun cbfun)
        //GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow* handle, GLFWwindowcontentscalefun cbfun)
        //void glfwPollEvents(void)
        //void glfwWaitEvents(void)
        //void glfwWaitEventsTimeout(double timeout)
        //void glfwPostEmptyEvent(void)
        void MakeContextCurrent() {
            glfwMakeContextCurrent(m_pWindow);
        }
       //GLFWwindow* glfwGetCurrentContext(void)
        
         //void glfwSwapBuffers(GLFWwindow* handle)
        

         //void glfwSwapInterval(int interval)
        

         //int glfwExtensionSupported(const char* extension)
        

         //GLFWglproc glfwGetProcAddress(const char* procname)
        



    };

}

#endif