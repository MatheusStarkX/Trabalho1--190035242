#include "Face.h"

Face::Face(GameObject &associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if (hitpoints <= 0){
        associated.RequestDelete();
        Sound *morte = (Sound*)associated.GetComponent("Musiquinha");
        morte->Play(1);                  
    }
}

void Face::Render(){
    
}

void Face::Update(float dt){
    if(Camera::pos.x != Camera::antigo.x){    
        associated.box.CSEx += Camera::pos.x - Camera::antigo.x;
        //printf("Posicao X: %d\n", (int)associated.box.CSEx);
    }
    if(Camera::pos.y != Camera::antigo.y){
        associated.box.CSEy += Camera::pos.y - Camera::antigo.y;
        //printf("Posicao Y: %d\n", (int)associated.box.CSEy);
    }

    if(InputManager::GetInstance().IsMouseDown(LEFT_MOUSE_BUTTON)) {
        int mouseX = InputManager::GetInstance().GetMouseX();
		int mouseY = InputManager::GetInstance().GetMouseY();
        if(associated.box.EstaDentro((float)mouseX, (float)mouseY)){
            //printf("MouseX: %d\n",mouseX);
            //printf("MouseY: %d\n",mouseY);
            Damage(std::rand() % 10 + 10);
        }
	}
}

bool Face::Is(std::string type){
    if (type == "Face")
        return true;
    else 
        return false;
}   
