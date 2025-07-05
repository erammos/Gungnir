//
// Created by eram on 5/7/25.
//

#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H



#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TransformComponent {
public:
    glm::vec3 position{0.0f};
    glm::vec3 rotation{0.0f};
    glm::vec3 scale{1.0f};

    [[nodiscard]] glm::mat4 GetTransform() const {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, position);
        transform = glm::rotate(transform, rotation.x, glm::vec3(1, 0, 0));
        transform = glm::rotate(transform, rotation.y, glm::vec3(0, 1, 0));
        transform = glm::rotate(transform, rotation.z, glm::vec3(0, 0, 1));
        transform = glm::scale(transform, scale);
        return transform;
    }
};

#endif //TRANSFORMCOMPONENT_H
