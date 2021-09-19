#include "Face.h"

Face::Face(GameObject &associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if (hitpoints <= 0){
        associated.RequestDelete();
    }
}

void Face::Render(){
    
}

void Face::Update(float dt){

}

bool Face::Is(std::string type){
    if (type == "Face")
        return true;
    else 
        return false;
}   
