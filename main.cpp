#include <iostream>

#include "Factories/AbstractFactory.h"
#include "Factories/SDLFactory.h"
#include "Controllers/Headers/Game.h"

int main(int argc, char *argv[]) {

    GameNs::AbstractFactory *AF = new SDLNs::SDLFactory();
    GameNs::Game *g = new GameNs::Game(AF);
    g->run();

    return 0;
}
