#include "Camera.h"

Vet2 Camera::speed(100,100);
Vet2 Camera::pos(0,0);
Vet2 Camera::antigo(0,0);
GameObject *Camera::focus = nullptr;

void Camera::Follow(GameObject *newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    antigo.x = pos.x;
    antigo.y = pos.y;
    if (focus != nullptr){
        pos = focus->box.Centro();
        pos.x -= 512;
        pos.y -= 300;
    }
    else{
        if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){
            pos.x += speed.x * dt;
        }
        if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){
            pos.x -= speed.x * dt;
        }
        if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){
            pos.y += speed.y * dt;
        }
        if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){
            pos.y -= speed.y * dt;
        }
    }
}