#include <iostream>
#include "Factories/Factory.h"
#include "Factories/SDLFactory.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    Abstract::Factory *AF;

    //Use try catch to handle failed initialisation of SDL or loading of media
    try {
        //create SDL factory
        AF = new SDL::SDLFactory();
        //initialise game class
        Game *g = Game::getInstance(AF);
        //run game
        g->run();

        //Deallocate memory
        Game::destroyGame();
        delete AF;


    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << "\n";
        //Deallocate memory
        Game::destroyGame();
        delete AF;
    }

    return 0;
}
