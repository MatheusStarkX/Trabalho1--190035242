#include "Sound.h"
#include "Game.h"
#include "Resources.h"

Sound::Sound(GameObject &associated) : Component(associated) {
    chunk = nullptr;
}

Sound::Sound(std::string file, GameObject &associated) : Component(associated) {
    chunk = nullptr;
    Open(file);
}

void Sound::Play(int times){
    times = 1;
    channel = Mix_PlayChannel(-1, chunk, times);
    if (channel == -1)
        printf("Problema no play dos canais: %s\n", SDL_GetError());
}

void Sound::Stop(){
    if (!IsOpen())
        Mix_HaltChannel(channel);
}

void Sound::Open(std::string file){
    chunk = Resources::GetSound(file);
    if (!IsOpen())
        printf("Problema no carregamento da música: %s\n", SDL_GetError());
}

bool Sound::IsOpen(){
    if (chunk == nullptr)
        return false;
    else
        return true;
}

Sound::~Sound(){
    if (!IsOpen()){
        Stop();
    }
    chunk = nullptr;
}

void Sound::Update(float dt){

}

bool Sound::Is(std::string type){
    if (type == "Musiquinha")
        return true;
    else 
        return false;
}

void Sound::Render(){

}
