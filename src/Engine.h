//
// Created by eram on 3/7/25.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <memory>

#include "Shader.h"
#include "Window.h"

namespace gngr {

class Engine {
    std::unique_ptr<Window>  window;
    std::shared_ptr<Shader> activeShader;
public:
    bool Initialize();            // Init all subsystems
    void Run();                   // Main loop
    void Shutdown();              // Cleanup resources

private:
    void ProcessInput();
    void Update(float deltaTime);
    void Render();
};

} // Gngr

#endif //ENGINE_H
