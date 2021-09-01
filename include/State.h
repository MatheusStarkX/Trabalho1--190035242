#define INCLUDE_SDL
#include "SDL_include.h"

//#include <SDL2/SDL.h>
#include <string>
#include "Sprite.h"
#include "Music.h"
#ifndef STAGE_H
#define STAGE_H

class State {
    private:
        Sprite bg;
        Music music;
        bool quitRequested;
    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(); // float dt
        void Render();
};

#endif