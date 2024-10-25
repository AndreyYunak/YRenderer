#pragma once

#include "YRendererCore/Application.hpp"
#include "YRendererCore/Scene.h"

#include <glad/gl.h>


//#include "YRendererCore/Window.hpp"
//#include "YRendererCore/Event.hpp"

//#include "YRendererCore/gpu/opengl/gl_Renderer.hpp"

//#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


namespace YRenderer {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	int Application::start(unsigned int window_width, unsigned int window_height, const char* title)
    {
        [[maybe_unused]] glfw::GlfwLibrary library = glfw::init();

        glfw::WindowHints hints;
        hints.clientApi = glfw::ClientApi::OpenGl;
        hints.contextVersionMajor = 4;
        hints.contextVersionMinor = 6;
        hints.apply();
        // Or with C++20:
        //glfw::WindowHints{
        //        .clientApi = glfw::ClientApi::OpenGl,
        //        .contextVersionMajor = 4,
        //        .contextVersionMinor = 6}
        //        .apply();
        glfw::Window wnd(800, 600, "GLFWPP basic example");

        //m_pWindow = std::make_unique<Window>(title, window_width, window_height);
        
        YRenderer::Camera camera(glm::vec3(30.0f, 30.0f, 30.0f));
        //m_pWindow->camera = &camera; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


        /*
        m_event_dispatcher.add_event_listener<EventMouseMoved>(
            [](EventMouseMoved& event)
            {
                //LOG_INFO("[MouseMoved] Mouse moved to {0}x{1}", event.x, event.y);
            });

        m_event_dispatcher.add_event_listener<EventWindowResize>(
            [](EventWindowResize& event)
            {
                //LOG_INFO("[Resized] Changed size to {0}x{1}", event.height, event.height);
            });

        m_event_dispatcher.add_event_listener<EventWindowClose>(
            [&](EventWindowClose& event)
            {
                //LOG_INFO("[WindowClose]");
                m_bCloseWindow = true;
            });

        m_pWindow->set_event_callback(
            [&](BaseEvent& event)
            {
                //LOG_INFO("[EVENT] Changed size to {0}x{1}", event.width, event.height);
                //std::cout << "Changed size to " << event.width << ", " << event.height <<  std::endl;
                m_event_dispatcher.dispatch(event);
            }
        );

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true); //comment this in RELEASE!

        m_pWindow->CreateWindow(window_width, window_height, title);
        */

        /* Make the window's context current */
        //m_pWindow->MakeContextCurrent();
        glfw::makeContextCurrent(wnd);
        int version = gladLoadGL(glfwGetProcAddress); //if (glewInit() != GLEW_OK)
        if (version == 0) {
            std::cout << "Failed to initialize OpenGL context\n";
            throw std::runtime_error("Could not initialize GLAD");
            // return -1;
        }
        
        
        scene::Scene* currentScene = nullptr;
        scene::SceneMenu* sceneMenu = new scene::SceneMenu(currentScene);
        currentScene = sceneMenu;
        //scene::SceneTest sceneTest();
        //SceneTextureSimple

        //sceneMenu->RegScene<scene::SceneTest>("Scene Test");
        //sceneMenu->RegScene<scene::SceneCurves>("SceneCurves");
        //sceneMenu->RegScene<scene::SceneTexture>("SceneTexture");
        //sceneMenu->RegScene<scene::SceneTextureSimple>("SceneTextureSimple");

        Shader* sceneShader = new Shader("./Shader/shader_texture.vs", "./Shader/shader_texture.frag");
        float vertices[32] = {
            // positions          // colors           // texture coords
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
        };
        unsigned int indices[6] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };
        unsigned int VBO, VAO, EBO;
        //unsigned int texture1, texture2;
        glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(GLuint) * 6), &indices[0], GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		sceneShader->use();
		
        // Window::WindowHint(YRenderer::WindowHints::DOUBLEBUFFER, 1);
            
        while (!wnd.shouldClose())
        {
            double time = glfw::getTime();
            glClearColor((sin(time) + 1.0) / 2.0, (cos(time) + 1.0) / 2.0, (-sin(time) + 1.0) / 2.0, 0.0);
            glClear(GL_COLOR_BUFFER_BIT);

            //m_pWindow->on_update_begin();
            on_update();
           
/*
            // render container
            sceneShader->use();
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            //m_pWindow->on_update_end();
            */

            glfw::pollEvents();
            wnd.swapBuffers();
        }
        //m_pWindow = nullptr;
        
        return 0;
    }
}