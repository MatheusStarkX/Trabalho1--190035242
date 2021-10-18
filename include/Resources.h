#ifndef RESOURCES_H
#define RESOURCES_H

#include <unordered_map>
#include <string>
#include "Game.h"

class Resources {
    private:
        static std::unordered_map<std::string, SDL_Texture*> imageTable;
        //std::unordered_map<std::string, Mix_Music*> musicTable; 
        static std::unordered_map<std::string, Mix_Chunk*> soundTable;
    public:
        static SDL_Texture *GetImage(std::string file);
        static void ClearImages();
        //Mix_Music *GetMusic(std::string file);
        //void ClearMusics();
        static Mix_Chunk *GetSound(std::string file);
        static void ClearSounds();     
};

#endif