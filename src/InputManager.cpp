#include "InputManager.h"

std::unordered_map<int, bool> InputManager::keyState = {};
std::unordered_map<int, int> InputManager::keyUpdate = {};

InputManager &InputManager::GetInstance(){
    static InputManager instancia;
    return instancia;
}

InputManager::InputManager(){
    mouseState[6] = {false};
    mouseUpdate[6] = {0};
    quitRequested = false;
    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;
}

void InputManager::Update(){
    SDL_Event event;
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    updateCounter++;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_KEYDOWN){
            if(event.key.repeat != 1){
                unsigned index = event.key.keysym.sym;

                auto tecla = keyState.find(index);
                if (tecla == keyState.end()){
                    keyState[index] = true;
                }
                else{
                    tecla->second = true;
                }

                auto denovo = keyUpdate.find(index);
                if (denovo == keyUpdate.end()){
                    keyUpdate[index] = updateCounter;
                }
                else{
                    denovo->second = updateCounter;
                }
            }
        }
        if (event.type == SDL_KEYUP){
            if(event.key.repeat != 1){
                unsigned index = event.key.keysym.sym;

                auto tecla = keyState.find(index);
                if (tecla == keyState.end()){
                    keyState[index] = false;
                }
                else{
                    tecla->second = false;
                }

                auto denovo = keyUpdate.find(index);
                if (denovo == keyUpdate.end()){
                    keyUpdate[index] = updateCounter;
                }
                else{
                    denovo->second = updateCounter;
                }
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN){
            if(event.key.repeat != 1){
                if(event.button.button == SDL_BUTTON_LEFT){
                    mouseState[1] = true;
                    mouseUpdate[1] = updateCounter;
                }
                if(event.button.button == SDL_BUTTON_MIDDLE){
                    mouseState[2] = true;
                    mouseUpdate[2] = updateCounter;
                }
                if(event.button.button == SDL_BUTTON_RIGHT){
                    mouseState[3] = true;
                    mouseUpdate[3] = updateCounter;
                }
                if(event.button.button == SDL_BUTTON_X1){
                    mouseState[4] = true;
                    mouseUpdate[4] = updateCounter;
                }
                if(event.button.button == SDL_BUTTON_X2){
                    mouseState[5] = true;
                    mouseUpdate[5] = updateCounter;
                }
            }
        }
        if (event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                mouseState[1] = false;
                mouseUpdate[1] = updateCounter;
            }
            if(event.button.button == SDL_BUTTON_MIDDLE){
                mouseState[2] = false;
                mouseUpdate[2] = updateCounter;
            }
            if(event.button.button == SDL_BUTTON_RIGHT){
                mouseState[3] = false;
                mouseUpdate[3] = updateCounter;
            }
            if(event.button.button == SDL_BUTTON_X1){
                mouseState[4] = false;
                mouseUpdate[4] = updateCounter;
            }
            if(event.button.button == SDL_BUTTON_X2){
                mouseState[5] = false;
                mouseUpdate[5] = updateCounter;
            }      
        }
        if (event.type == SDL_QUIT){
            printf("quero sair\n");
            quitRequested = true;
        }        
    }
}

bool InputManager::IsKeyDown(int key){
    auto tecla = keyState.find(key);
    if (tecla == keyState.end())
        return false;
    else   
        return tecla->second;
}

bool InputManager::KeyPress(int key){
    auto tecla = keyState.find(key);
    auto denovo = keyUpdate.find(key);
    if (tecla == keyState.end())
        return false;
    else{
        if (denovo == keyUpdate.end())
            return false;
        else{
            return tecla->second && keyUpdate[key] == updateCounter;
        }
    }
}

bool InputManager::KeyRelease(int key){
    auto tecla = keyState.find(key);
    auto denovo = keyUpdate.find(key);
    if (tecla == keyState.end())
        return false;
    else{
        if (denovo == keyUpdate.end())
            return false;
        else{
            return !(tecla->second) && keyUpdate[key] == updateCounter;
        }
    }
}

bool InputManager::IsMouseDown(int botao){
    return mouseState[botao];
}

bool InputManager::MousePress(int botao){
    return mouseUpdate[botao];
}

bool InputManager::MouseRelease(int botao){
    return mouseUpdate[botao];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}