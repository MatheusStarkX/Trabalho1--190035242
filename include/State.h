#define INCLUDE_SDL
#define _USE_MATH_DEFINES
#include "SDL_include.h"

#include <string>
#include <memory>

#include "Sprite.h"
#include "Sound.h"
#include "Geometria.h"
#include "Face.h"
#include "TileMap.h"

#ifndef STAGE_H
#define STAGE_H

class State {
    private:
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
    public:
        State();
        ~State();
        void Input();
        void AddObject(int mouseX, int mouseY);
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt); // float dt
        void Render();
};

#endif