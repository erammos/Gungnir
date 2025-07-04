//
// Created by eram on 3/7/25.
//

#include "Engine.h"

#include <iostream>
#include <thread>


namespace Gngr {
} // Gngr
bool gngr::Engine::Initialize() {

    this->window = std::make_shared<Window>();
    this->window->Create("Engine", 800,600);
    this->renderer = std::make_unique<Renderer>();
    this->renderer->Initialize();
     this->activeShader = std::make_shared<Shader>();
     this->activeShader->LoadFromFiles("resources/simple.vs", "resources/simple.fs");
    return true;
}

void gngr::Engine::Run() {

    double lastTime = glfwGetTime();
    while (!window->ShouldClose()) {

        Update(glfwGetTime() - lastTime);
        Render();
        window->SwapBuffers();
        window->PollEvents();
        lastTime = glfwGetTime();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void gngr::Engine::Shutdown() {
    window->Destroy();
}

void gngr::Engine::ProcessInput() {
}

void gngr::Engine::Update(float deltaTime) {

}

void gngr::Engine::Render() {

}
