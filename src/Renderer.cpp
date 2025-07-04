//
// Created by Elias Rammos on 4/7/25.
//

#include "Renderer.h"


namespace gngr {
    void Renderer::Initialize() {
        gladLoadGL();
    }

    void Renderer::Clear() {
    }

    void Renderer::DrawMesh(Mesh &mesh, Shader &shader, TransformComponent &transform) {
    }

    void Renderer::Present() {
    }
} // gngr