#ifndef SOUND_H
#define SOUND_H

#include "GameObject.h"
#include "Game.h"
#include "Resources.h"
#include <string>

class Sound : public Component {
    private:   
        Mix_Chunk *chunk;
        int channel;
    public:
        Sound(GameObject &associated);
        Sound(std::string file, GameObject &associated);
        ~Sound();
        void Play(int times);
        void Stop();
        void Open(std::string file);
        bool IsOpen();
        void Render();
        void Update(float dt);
        bool Is(std::string type);
};

#endif