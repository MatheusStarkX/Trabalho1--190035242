#include "Sprite.h"
//#include "Stage.h"
#include "Game.h"

//Game jogo = Game::GetInstance();

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if (IsOpen())
        SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Sprite::Open(std::string file){
    if (IsOpen())
        SDL_DestroyTexture(texture);

    texture = IMG_LoadTexture(Game::GetInstance("",0,0).GetRenderer(), file.c_str());
    if(!IsOpen())
        printf("Renderizador com problemas: %s\n", SDL_GetError());

    SDL_QueryTexture(texture, nullptr, nullptr, &largura, &altura);
    SetClip(0,0,largura,altura);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    if (SDL_RenderCopy(Game::GetInstance("",0,0).GetRenderer(), texture, &clipRect , &dstrect) == -1)
        printf("SDL_RenderCopy com problemas: %s\n", SDL_GetError());
}

int Sprite::GetLargura(){
    return largura;
}

int Sprite::GetAltura(){
    return altura;
}

bool Sprite::IsOpen(){
    if (texture == nullptr)
        return false;
    else
        return true;
}
