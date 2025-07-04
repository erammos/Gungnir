//
// Created by eram on 3/7/25.
//

#include "Window.h"

using namespace gngr;
// Gngr
void Window::Create(const std::string &title, int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    this->glfwWindow = glfwCreateWindow(800, 600, title.c_str(), NULL, NULL);
    this->width = width;
    this->height = height;
    if (!this->glfwWindow) {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->glfwWindow);
   // glfwSwapInterval(1);


}

void Window::Destroy() const {
    glfwDestroyWindow(this->glfwWindow);
}

void Window::PollEvents() {
    glfwGetFramebufferSize(this->glfwWindow, &this->width, &this->height);
    glfwPollEvents();
}

void Window::SwapBuffers() const {
    glfwSwapBuffers(this->glfwWindow);
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(this->glfwWindow);
}
