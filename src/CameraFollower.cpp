#include "CameraFollower.h"

CameraFollower::CameraFollower(GameObject &game) : Component(game){

}

void CameraFollower::Update(float dt){
    associated.box.CSEx = Camera::pos.x;
    associated.box.CSEy = Camera::pos.y;   
}

void CameraFollower::Render(){
    
}

bool CameraFollower::Is(std::string type){
    if (type == "Camera Seguidora")
        return true;
    else 
        return false;
}   