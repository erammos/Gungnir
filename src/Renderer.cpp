//
// Created by Elias Rammos on 4/7/25.
//

#include "Renderer.h"

#include "Shader.h"
#include "Window.h"


namespace gngr {
    void Renderer::Initialize() {
        gladLoadGL();
    }

    void Renderer::Clear() {
    }

    void Renderer::DrawMesh(Mesh &mesh, Shader &shader, TransformComponent &transform) {
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


        glViewport(0, 0, this->window->GetWidth(), this->window->GetHeight());

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Use();
        // Update uniforms
        // Draw the full-screen quad
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Renderer::Present() {
    }
} // gngr