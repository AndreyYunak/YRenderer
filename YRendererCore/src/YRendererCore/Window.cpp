#if 0


#include "YRendererCore/Window.hpp"
#include "YRendererCore/gpu/opengl/gl_Renderer.h"

#include <iostream>


#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>
//#include <imgui/>

namespace YRenderer {

    static bool s_GLFW_initialized = false;

    Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : m_data({ std::move(title), width, height })
    {
        int resultCode = init();
       

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplOpenGL3_Init();
        ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_pWindow);
        number_of_windows--;
        shutdown();
    }

    int Window::init()
    {
        // glfw: initialize and configure
        if (!s_GLFW_initialized)
        {
            if (!glfwInit())
            {
                std::cout << "Can't initialize GLFW!" << std::endl;
                //LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }

        }
        s_GLFW_initialized = true;
        std::cout << "Initialize GLFW!" << std::endl;
        return 0;
    }

    

    void Window::shutdown()
    {
        if (YRenderer::s_GLFW_initialized && Window::number_of_windows == 0)
        {
            glfwTerminate();
        }
    }

    void Window::on_update_begin()
    {
        glClearColor(m_background_color[0], m_background_color[1], m_background_color[2], m_background_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize.x = static_cast<float>(get_width());
        io.DisplaySize.y = static_cast<float>(get_height());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        ImGui::Begin("Background Color Window");
        ImGui::ColorEdit4("Background Color", m_background_color);

        if (ImGui::TreeNode("Configuration##2"))
        {
            ImGui::SeparatorText("General");
            ImGui::CheckboxFlags("io.ConfigFlags: NavEnableKeyboard", &io.ConfigFlags, ImGuiConfigFlags_NavEnableKeyboard);
            ImGui::CheckboxFlags("io.ConfigFlags: NavEnableGamepad", &io.ConfigFlags, ImGuiConfigFlags_NavEnableGamepad);
            ImGui::CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", &io.ConfigFlags, ImGuiConfigFlags_NavEnableSetMousePos);
            ImGui::CheckboxFlags("io.ConfigFlags: NoMouse", &io.ConfigFlags, ImGuiConfigFlags_NoMouse);
            ImGui::TreePop();
            ImGui::Spacing();
            ImGui::Button("hi!");
        }
        ImGui::End();

    }

    void Window::on_update_end()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();
    }

}
#endif