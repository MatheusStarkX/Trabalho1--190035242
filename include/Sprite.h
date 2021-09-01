#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <string>
#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
    private:
        SDL_Texture *texture;
        int largura = 1024;
        int altura = 600;
        SDL_Rect clipRect;
    public:
        Sprite();
        Sprite(std::string file);
        ~Sprite();
        void Open(std::string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y);
        int GetLargura();
        int GetAltura();
        bool IsOpen();
};

#endif