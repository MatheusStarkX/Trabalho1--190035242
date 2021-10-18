#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "InputManager.h"

class Camera {
    private:
        static GameObject *focus;
    public:
        static Vet2 antigo;
        static Vet2 pos;
        static Vet2 speed;
        static void Follow(GameObject *newFocus);
        static void Unfollow();
        static void Update(float dt);
};

#endif