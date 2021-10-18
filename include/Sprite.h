#ifndef SPRITE_H
#define SPRITE_H

#include "GameObject.h"
#include <string>

class Sprite : public Component {
    private:
        SDL_Texture *texture;
        int largura;
        int altura;
        SDL_Rect cliprect;
    public:
        Sprite();
        Sprite(std::string file, GameObject &associated);
        ~Sprite();
        void Open(std::string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        void Render(float x, float y);
        void Update(float dt);
        bool Is(std::string type);
        int GetLargura();
        int GetAltura();
        bool IsOpen();
};

#endif