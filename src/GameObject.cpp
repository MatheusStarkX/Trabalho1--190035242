#include "GameObject.h"

Component::Component(GameObject &associated) : associated(associated){

}

Component::~Component(){

}

GameObject::GameObject(){
    isDead = false;   
}

GameObject::~GameObject(){
    int i = components.size()-1;
    while (i >= 0){
        components.erase(components.begin() + i);
        i--;
    }
    components.clear();   
}

void GameObject::Update(float dt){
    for(unsigned int i=0; i<components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for(unsigned int i=0; i<components.size(); i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component *cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt){
    for(unsigned int i=0; i<components.size();i++){
        if (components[i].get() == cpt){
            components.erase(components.begin()+i);
            break;
        }            
    }
}

Component *GameObject::GetComponent(std::string type){
    for(unsigned int i=0; i<components.size();i++){
        if (components[i]->Is(type))
            return components[i].get();          
    }
    return nullptr;
}

