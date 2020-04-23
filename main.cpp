
#include "Factories/AbstractFactory.h"
#include "Factories/SDLFactory.h"
#include "Controllers/Headers/Game.h"

int main(int argc, char *argv[]) {
    //create SDL factory
    GameNs::AbstractFactory *AF = new SDLNs::SDLFactory();
    //initialise game class
    GameNs::Game *g = GameNs::Game::getInstance(AF);
    //run game
    g->run();

    //Deallocate memory
    delete g;
    delete AF;

    return 0;
}
