//
// Created by eram on 5/7/25.
//

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
class Shader;
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture {
    unsigned int id;
    std::string type; // e.g., "texture_diffuse", "texture_specular"
};


class Mesh {
public:
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;

    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures);

    void Draw(Shader &shader);

private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

#endif //MESH_H
