#include <iostream>
#include <memory>

#include <YRendererCore/Application.hpp>


class MyApp : public YRenderer::Application
{
    virtual void on_update() override
    {
      // m_pWindow->m_render->DrawArrays();
    }

   
};


int main()
{
    auto myApp = std::make_unique<MyApp>();

    int returnCode = myApp->start(1024, 768, "My first App");

    return returnCode;
}