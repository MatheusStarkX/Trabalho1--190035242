#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <string>
#include "Game.h"

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT


class InputManager {
    private:
        bool mouseState[6];
        int mouseUpdate[6];
        static std::unordered_map<int, bool> keyState;
        static std::unordered_map<int, int> keyUpdate;
        bool quitRequested;
        int updateCounter;
        int mouseX;
        int mouseY;
    public:
        static InputManager& GetInstance();
        InputManager();
        //~InputManager();
        void Update();
        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool IsKeyDown(int key);
        bool MousePress(int botao);
        bool MouseRelease(int botao);
        bool IsMouseDown(int botao);
        int GetMouseX();
        int GetMouseY();
        bool QuitRequested();    
};

#endif