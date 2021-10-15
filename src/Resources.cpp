#include "Resources.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable = {};
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable = {};

SDL_Texture *Resources::GetImage(std::string file){
    auto imagem = imageTable.find(file);
    if (imagem == imageTable.end()){
        //printf("Nao encontrei a imagem, vou aloca-la!\n");
        SDL_Texture *textura = IMG_LoadTexture(Game::GetInstance("",0,0).GetRenderer(), file.c_str());
        if (textura == nullptr)
            printf("Falha na alocação da textura!\n");
        else
            imageTable[file] = textura;
        
        return textura;
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

Mix_Chunk *Resources::GetSound(std::string file){
    auto som = soundTable.find(file);
    if (som == soundTable.end()){
        //printf("Não encontrei o som, vou aloca-lo!\n");
        Mix_Chunk *msc = Mix_LoadWAV(file.c_str());
        if (msc == nullptr)
            printf("Falha na alocação do som!\n");
        else
            soundTable[file] = msc;
        
        return msc;
    }
    else{
        return som->second;
    }
}

void Resources::ClearSounds(){
    if(!soundTable.empty()){
        for (auto i = soundTable.begin(); i != soundTable.end(); i++ ){
            Mix_FreeChunk(i->second);
        }
        soundTable.clear();
    }
}