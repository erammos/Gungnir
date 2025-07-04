//
// Created by eram on 3/7/25.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "GLFW/glfw3.h"

namespace gngr {
    class Window {
    public:
        Window() = default;

        ~Window() = default;

        void Create(const std::string &title, int width, int height);

        void Destroy() const;

        void PollEvents();

        void SwapBuffers() const;

        [[nodiscard]] bool ShouldClose() const;

        [[nodiscard]] int GetWidth() const {
            return width;
        };

        [[nodiscard]] int GetHeight() const {
            return height;
        };

    private:
        GLFWwindow *glfwWindow{};
        int width{};
        int height{};
    };
} // Gngr

#endif //WINDOW_H
