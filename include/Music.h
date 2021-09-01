#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_mixer.h>
#include <string>

using namespace std;
#ifndef MUSIC_H
#define MUSIC_H

class Music {
    private:   
        Mix_Music *music;
        int msToStop = 1500;
    public:
        Music();
        Music(string file);
        ~Music();
        void Play(int times);
        void Stop(int msToStop);
        void Open(string file);
        bool IsOpen();
};

#endif