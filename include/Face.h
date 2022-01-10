#ifndef FACE_H
#define FACE_H

#include "GameObject.h"
#include "Sound.h"
#include "InputManager.h"

#include <string>

class Face : public Component {
    private:
        int hitpoints;
    public:
        Face(GameObject &associated);
        void Damage(int damage);
        void Render();
        void Update(float dt);
        bool Is(std::string type);
};

#endif