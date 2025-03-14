#pragma once

//#include "YRendererCore/Event.hpp"
#include "YRendererCore/camera.h"

#include "YRendererCore/gpu/opengl/gl_Renderer.h"
#include "YRendererCore/gpu/opengl/gl_ShaderProgram.h"

#include "YRendererCore/Scene.h"

#include <memory>
#include <glm/glm.hpp>

#include <glfwpp/glfwpp.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <iostream>


namespace YRenderer {


    class Application
    {
    public:
        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        virtual int start(unsigned int window_width, unsigned int window_height, const char* title);

        virtual void on_update() {}
        
        std::unique_ptr<glfw::Window> wnd;
        scene::Scene* currentScene = nullptr;
        scene::SceneMenu* sceneMenu = new scene::SceneMenu(currentScene);
        
        Shader* sceneShader;
        //std::unique_ptr<class Window> m_pWindow;

    private:
        //std::unique_ptr<class Window> m_pWindow;
        //std::unique_ptr<class gl_Renderer> m_render;
        
        //EventDispatcher m_event_dispatcher;
        //bool m_bCloseWindow = false;
    };

}