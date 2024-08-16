#pragma once

#include "YRendererCore/Application.hpp"
#include "YRendererCore/Window.hpp"
#include "YRendererCore/Event.hpp"
#include "YRendererCore/gpu/opengl/gl_Renderer.cpp"

#include <GLFW/glfw3.h>
#include <iostream>


namespace YRenderer {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	int Application::start(unsigned int window_width, unsigned int window_height, const char* title)
    {
        m_pWindow = std::make_unique<Window>(title, window_width, window_height);
        m_render = std::make_unique<gl_Renderer>();
        
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

            
        while (!m_bCloseWindow)
        {
            m_pWindow->on_update();
            on_update();
        }
        m_pWindow = nullptr;
        
        return 0;
    }
}