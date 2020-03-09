#include <iostream>
#include <SDL.h>
using namespace std;
#include <stdio.h>
#include "../Headers/Graphics.h"

int main(int argc, char *argv[]) {

    Graphics test;
    //check if everything was initialised correctly
    test.initialise();
    while (test.getRunningState())
    {
        test.Events();
        test.Update();
        test.Render();
    }
    //clean everything
    test.Clean();

    return 0;
}
