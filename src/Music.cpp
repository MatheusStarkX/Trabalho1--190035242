#include "Music.h"

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    music = nullptr;
    Open(file);
}

void Music::Play(int times){
    if (Mix_PlayMusic(music, times) == -1)
        printf("Problema na abertura da música: %s\n", SDL_GetError());
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
    if (music == nullptr)
        printf("Problema no carregamento da música: %s\n", SDL_GetError());
}

bool Music::IsOpen(){
    if (music == nullptr)
        return false;
    else
        return true;
}

Music::~Music(){
    Stop(msToStop);
    Mix_FreeMusic(music);
    music = nullptr;
}
