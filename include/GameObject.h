#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include "Geometria.h"
#include <vector>
#include <memory>
#include <string>

class Component;

class GameObject {
    private:
        std::vector <std::unique_ptr<Component>> components;
        bool isDead;
    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);
        Rect box;
};

class Component {
    protected:
        GameObject &associated;
    public:
        Component(GameObject &associated);
        virtual ~Component();
        void virtual Update(float dt) = 0;
        void virtual Render() = 0;
        bool virtual Is(std::string type) = 0;
};

#endif