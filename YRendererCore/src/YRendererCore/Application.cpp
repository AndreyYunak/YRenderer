#pragma once

#include "YRendererCore/Application.hpp"


#include <glad/gl.h>


//#include "YRendererCore/Window.hpp"
//#include "YRendererCore/Event.hpp"

//#include "YRendererCore/gpu/opengl/gl_Renderer.hpp"

//#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>



namespace YRenderer {

  void cleanupImgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

template<typename Func>
void renderImgui(Func&& guiRenderFunc_)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    guiRenderFunc_();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

   /* if(ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        glfw::Window& backupCurrentContext = glfw::getCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfw::makeContextCurrent(backupCurrentContext);
    } */
}

void initImgui(const glfw::Window& wnd)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;

    ImGui_ImplGlfw_InitForOpenGL(wnd, true);
    ImGui_ImplOpenGL3_Init();
}



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

        wnd = std::make_unique<glfw::Window>(800, 600, "GLFWPP basic example");
        
        glfw::makeContextCurrent(*wnd);
        int version = gladLoadGL(glfwGetProcAddress); //if (glewInit() != GLEW_OK)
        if (version == 0) {
            std::cout << "Failed to initialize OpenGL context\n";
            throw std::runtime_error("Could not initialize GLAD");
            // return -1;
        }
        
        initImgui(*wnd);
        
        YRenderer::Camera camera(glm::vec3(30.0f, 30.0f, 30.0f));


        wnd->framebufferSizeEvent.setCallback([](glfw::Window&, int width, int height) {
          glViewport(0, 0, width, height);
        });
        wnd->keyEvent.setCallback([&](glfw::Window&, glfw::KeyCode keyCode_, int scanCode_, glfw::KeyState state_, glfw::ModifierKeyBit modifiers_) {
          bool val = true;
          if(modifiers_ & glfw::ModifierKeyBit::Control)
          {
              val = false;
          }
          switch(keyCode_)
          {
              case glfw::KeyCode::F:
                  wnd->setAttribFloating(val);
                  break;
              case glfw::KeyCode::R:
                  wnd->setAttribResizable(val);
                  break;
              case glfw::KeyCode::D:
                  wnd->setAttribDecorated(val);
                  break;
              default:
                  break;
          }
        });
      
        
        
        

        currentScene = sceneMenu;
        //sceneShader = new Shader("./Shader/shader_texture.vs", "./Shader/shader_texture.frag");
        
        //scene::SceneTest sceneTest();
        //SceneTextureSimple

        //sceneMenu->RegScene<scene::SceneTest>("Scene Test");
        //sceneMenu->RegScene<scene::SceneCurves>("SceneCurves");
        //sceneMenu->RegScene<scene::SceneTexture>("SceneTexture");
        //sceneMenu->RegScene<scene::SceneTextureSimple>("SceneTextureSimple");

    /*    
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
*/

		
        // Window::WindowHint(YRenderer::WindowHints::DOUBLEBUFFER, 1);
            
        while (!wnd->shouldClose())
        {
            double time = glfw::getTime();
            glClearColor((sin(time) + 1.0) / 2.0, (cos(time) + 1.0) / 2.0, (-sin(time) + 1.0) / 2.0, 0.0);
            glClear(GL_COLOR_BUFFER_BIT);
            
            
            //wnd.setTitle(std::to_string(glfw::getTime()).c_str());

            if(!wnd->getAttribFocused())
            {   
              wnd->requestAttention();
            }
            


            on_update();
           

            // render container
            //sceneShader->use();
            
            //currentScene->onImGuiRender();
            
            //glBindVertexArray(VAO);
            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            //m_pWindow->on_update_end();
            
            renderImgui([]() {
              ImGui::ShowDemoWindow();
            });



            glfw::pollEvents();
            wnd->swapBuffers();
        }
        cleanupImgui();
        
        return 0;
    }
}