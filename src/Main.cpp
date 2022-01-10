#include "Game.h"

int main(int argc, char *argv[]) {

    Game joguinho = Game::GetInstance("Matheus Felipe - 190035242", 600, 1024);
    joguinho.Run();
    joguinho.~Game();
    
    return 0;
}