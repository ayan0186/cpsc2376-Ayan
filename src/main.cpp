#include <iostream>
#include <SDL.h>
#include <GL/glew.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>

int main(int, char**) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL window with OpenGL context
    SDL_Window *window = SDL_CreateWindow("ImGui + SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create OpenGL context
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if (!gl_context) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW Initialization failed!" << std::endl;
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set up ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    // Set up ImGui SDL2 and OpenGL3 bindings
    if (!ImGui_ImplSDL2_InitForOpenGL(window, gl_context)) {
        std::cerr << "ImGui_ImplSDL2_InitForOpenGL failed!" << std::endl;
        ImGui::DestroyContext();
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (!ImGui_ImplOpenGL3_Init("#version 130")) {
        std::cerr << "ImGui_ImplOpenGL3_Init failed!" << std::endl;
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool done = false;
    SDL_Event event;

    // ImGui demo window flag
    bool show_demo_window = true;

    // Main rendering loop
    while (!done) {
        // Poll SDL events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
            }
            ImGui_ImplSDL2_ProcessEvent(&event);
        }

        // Start a new frame
        ImGui_ImplSDL2_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        // Show ImGui demo window
        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        // Render the ImGui draw data
        ImGui::Render();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f); // Clear color
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap the window
        SDL_GL_SwapWindow(window);
    }

    // Clean up ImGui and SDL
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
