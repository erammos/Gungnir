//
// Created by Elias Rammos on 4/7/25.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <memory>

#include "glad/glad.h"

namespace gngr {
    class Window;
    class Shader;
    class TransformComponent;
    class Mesh;
    class Renderer {

        private:
        std::shared_ptr<Window> window;
public:
    void Initialize();
    void Clear();
    void DrawMesh(Mesh&, Shader&, TransformComponent&);
    void Present();
};

} // gngr

#endif //RENDERER_H
