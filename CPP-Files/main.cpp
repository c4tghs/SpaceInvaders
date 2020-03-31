#include <iostream>

#include "../Factories/AbstractFactory.h"
#include "../Factories/SDLFactory.h"
#include "../Headers/Game.h"

int main(int argc, char *argv[]) {

    AbstractFactory *AF = new SDLFactory();
    Game *g = new Game(AF);
    g->run();

    return 0;
}
