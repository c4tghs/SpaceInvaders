#include <iostream>
#include <SDL.h>
using namespace std;
#include <stdio.h>
#include "../Factories/AbstractFactory.h"
#include "../Factories/SDLFactory.h"
#include "../Headers/Game.h"

int main(int argc, char *argv[]) {

    AbstractFactory *AF = new SDLFactory();
    Game *g = new Game(AF);
    cout << "Testing" << endl;
    g->run();

    /*SDLFactory test;
    //check if everything was initialised correctly
    test.initialise(960,640);
    while (test.getRunningState())
    {
        test.getEvents();
        test.Update();
        test.render();
    }
    //clean everything
    test.close();*/

    return 0;
}
