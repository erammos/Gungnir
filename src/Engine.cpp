//
// Created by eram on 3/7/25.
//

#include "Engine.h"

#include <iostream>
#include <thread>
#include <__ostream/basic_ostream.h>


namespace Gngr {
} // Gngr
bool gngr::Engine::Initialize() {

    this->window = std::make_unique<Window>();
    this->window->Create("Engine", 800,600);
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
    float vertices[] = {
        1.0f,  1.0f, 0.0f,  // top right
        1.0f, -1.0f, 0.0f,  // bottom right
       -1.0f, -1.0f, 0.0f,  // bottom left
       -1.0f,  1.0f, 0.0f   // top left
   };
    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    glViewport(0, 0, window->GetWidth(), window->GetHeight());

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    this->activeShader->Use();
    // Update uniforms
    float currentTime = glfwGetTime();
    // Draw the full-screen quad
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
