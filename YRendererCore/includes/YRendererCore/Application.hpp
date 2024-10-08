#pragma once

#include "YRendererCore/Event.hpp"

#include <memory>


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

    private:
        std::unique_ptr<class Window> m_pWindow;
        std::unique_ptr<class gl_Renderer> m_render;
        
        EventDispatcher m_event_dispatcher;
        bool m_bCloseWindow = false;
    };

}