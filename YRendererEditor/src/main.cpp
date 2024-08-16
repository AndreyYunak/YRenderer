#include <iostream>
#include <memory>

#include <YRendererCore/Application.hpp>

class MyApp : public YRenderer::Application
{
    virtual void on_update() override
    {
       
    }

   
};


int main()
{
    auto myApp = std::make_unique<MyApp>();

    int returnCode = myApp->start(1024, 768, "My first App");

    return returnCode;
}