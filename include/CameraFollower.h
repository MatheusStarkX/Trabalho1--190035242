#ifndef CAMERAFOLLOWER_H
#define CAMERAFOLLOWER_H

#include "GameObject.h"
#include "Camera.h"
#include <string>

class CameraFollower : public Component {
    public:
        CameraFollower(GameObject &game);
        void Update(float dt);
        void Render();
        bool Is(std::string type);
};

#endif