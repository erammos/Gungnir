//
// Created by Elias Rammos on 4/7/25.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "glad/glad.h"

namespace gngr {
    class Shader;
    class TransformComponent;
    class Mesh;
    class Renderer {
public:
    void Initialize();
    void Clear();
    void DrawMesh(Mesh&, Shader&, TransformComponent&);
    void Present();
};

} // gngr

#endif //RENDERER_H
