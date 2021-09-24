#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject &associated) : Component(associated) {
    texture = nullptr;
}

Sprite::Sprite(std::string file, GameObject &associated) : Component(associated){
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

    if (SDL_QueryTexture(texture, nullptr, nullptr, &largura, &altura) == -1)
        printf("Consulta da textura com problemas: %s\n", SDL_GetError());

    SetClip(0,0,largura,altura);
    associated.box = Rect(associated.box.CSEx,associated.box.CSEy,largura,altura);
}

void Sprite::SetClip(int x, int y, int w, int h){
    cliprect.x = x;
    cliprect.y = y;
    cliprect.w = w;
    cliprect.h = h;
}

void Sprite::Render(){
    SDL_Rect dstrect;
    dstrect.x = associated.box.CSEx;
    dstrect.y = associated.box.CSEy;
    dstrect.w = cliprect.w;
    dstrect.h = cliprect.h;

    if (SDL_RenderCopy(Game::GetInstance("",0,0).GetRenderer(), texture, &cliprect , &dstrect) == -1)
        printf("SDL_RenderCopy com problemas: %s\n", SDL_GetError());
}

void Sprite::Update(float dt){

}

bool Sprite::Is(std::string type){
    if (type == "Sprite de Face")
        return true;
    else 
        return false;
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
