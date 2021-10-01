#include "Resources.h"

SDL_Texture *Resources::GetImage(std::string file){
    auto imagem = imageTable.find(file);
    if (imagem == imageTable.end()){
        printf("Não encontrei a imagem, vou aloca-la!\n");
        SDL_Texture *textura = IMG_LoadTexture(Game::GetInstance("",0,0).GetRenderer(), file.c_str());
        if (textura == nullptr)
            printf("Falha na alocação da textura!\n");
        else{
            imageTable.emplace(file, textura);
            return textura;
        }
    }
    else{
        return imagem->second;
    }
}

void Resources::ClearImages(){
    if(!imageTable.empty()){
        for (auto i = imageTable.begin(); i != imageTable.end(); i++ ){
            SDL_DestroyTexture(i->second);
        }
        imageTable.clear();
    }
}