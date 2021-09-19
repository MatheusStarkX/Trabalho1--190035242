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
}

void Sprite::SetClip(int x, int y, int w, int h){
    cliprect.x = x;
    cliprect.y = y;
    cliprect.w = w;
    cliprect.h = h;
}

void Sprite::Render(){
    SDL_Rect dstrect;
    SetClip(associated.box.CSEx, associated.box.CSEy, associated.box.Larg, associated.box.Alt);
    dstrect.x = cliprect.x;
    dstrect.y = cliprect.y;
    dstrect.w = cliprect.w;
    dstrect.h = cliprect.h;

    printf("Eixo X: %d", cliprect.x);
    printf("\n");
    printf("Eixo Y: %d", cliprect.y);
    printf("\n");
    printf("Largura: %d", cliprect.w);
    printf("\n");
    printf("Altura: %d", cliprect.h);
    printf("\n\n");


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
