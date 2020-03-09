//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../Factories/AbstractFactory.h"

class Game {
public:
    Game(AbstractFactory *AF);
    void Run();

private:
    AbstractFactory* _factory;
};


#endif //PROJECT_GAME_H
