#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

//#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "State.h"

using namespace std;
#ifndef GAME_H
#define GAME_H

//const string titulo = "Matheus Felipe - 190035242";
//const int largura = 1024, altura = 600;

class Game {
    private:
        static Game *instance;
        SDL_Window *window;
        SDL_Renderer *renderer;
        State *state;
        Game (string titulo, int altura, int largura);
    public:
        ~Game ();
        void Run();
        SDL_Renderer *GetRenderer();
        State &GetState();
        static Game &GetInstance(string titulo, int altura, int largura);
};

#endif