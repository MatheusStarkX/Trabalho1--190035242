#include "Game.h"

Game *Game::instance = nullptr;
int frameStart=0;
float dt=0;

Game& Game::GetInstance(string titulo, int altura, int largura) {
    if (instance != nullptr)
        return *instance;
    else {    
        instance = new Game(titulo, altura, largura);
        return *instance;
    }
}

Game::Game(string titulo, int altura, int largura){
    // Instancia a classe
    if (instance != nullptr)
        printf("Problema de lógica: %s\n", SDL_GetError());
    else
        instance = this;

    // Inicializa a biblioteca SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) != 0)
        printf("SDL_Init falhou: %s\n", SDL_GetError());

    // Inicializa a biblioteca de imagens
    if (IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF) == 0)
        printf("IMG_Init falhou: %s\n", SDL_GetError());

    // Inicializa a biblioteca de áudio 
    Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|MIX_INIT_OGG);
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
        printf("Mix_OpenAudio falhou!");
    Mix_AllocateChannels(32);

    // Inicializa a janela
    window = SDL_CreateWindow(titulo.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, largura, altura, 0);
    if (window == nullptr)
        printf("Window com problemas: %s\n", SDL_GetError());
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
        printf("Renderer com problemas: %s\n", SDL_GetError());

    // Instancia um State (Estado) do jogo
    state = new State(); 
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State &Game::GetState(){
    return *state;
}

SDL_Renderer *Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while(state->QuitRequested() == false){
        CalculateDeltaTime();
        //printf("primeiro\n");
        InputManager::GetInstance().Update();
        //printf("Deu bom\n");
        state->Update(GetDeltaTime());
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
    //recursos->ClearMusics();
    Resources::ClearSounds();
}

void Game::CalculateDeltaTime(){
    int antigo = frameStart;
    frameStart = SDL_GetTicks();
    dt = frameStart - antigo;
    dt /= 1000;
}

float Game::GetDeltaTime(){
    return dt;
}