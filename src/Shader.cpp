//
// Created by Elias Rammos on 4/7/25.
//

#include "Shader.h"

#include <fstream>
#include <iostream>


namespace gngr {
    std::string read_file(const std::string &filename) {
        std::ifstream stream;
        stream.open(filename);
        std::string line;
        std::string output;
        while (getline(stream, line)) {
            output+= line + "\n";
        }
        stream.close();
        return output;
    }
    void Shader::LoadFromFiles(const std::string &vertexPath, const std::string &fragmentPath) {
        std::string fs_string = read_file(fragmentPath);
        std::string vs_string = read_file(vertexPath);
        const GLchar * fs_source = fs_string.c_str();
        const GLchar * vs_source = vs_string.c_str();

        int success;
        char infoLog[512];

        // Compile Fragment Shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fs_source, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Compile Vertex Shader
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vs_source, nullptr);
        glCompileShader(vertexShader);
        // --- FIX 1: Check vertexShader, not fragmentShader ---
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Link Shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // --- FIX 2: Add check for linking errors ---
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        this->program_id = shaderProgram;
        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);
    }

    void Shader::Use() {
        glUseProgram(program_id);
    }
} // gngr