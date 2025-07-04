//
// Created by Elias Rammos on 4/7/25.
//

#ifndef SHADER_H
#define SHADER_H
#include "Renderer.h"
#include <string>

namespace gngr {

class Shader {
    public:
   void LoadFromFiles(const std::string &vertexPath, const std::string &fragmentPath);
    void Use();
private:
    unsigned int program_id{};
};

} // gngr

#endif //SHADER_H
