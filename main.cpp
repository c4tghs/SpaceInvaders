
#include <iostream>
#include "Factories/Factory.h"
#include "Factories/SDLFactory.h"
#include "Game.h"

struct AllocationMetrics{
    uint32_t TotalAllocated =0;
    uint32_t TotalFreed =0;

    uint32_t CurrentUsage(){return TotalAllocated-TotalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

static void PrintMemoryUsage()
{
    std::cout << "Memory usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;
    PrintMemoryUsage();
    return malloc(size);
}

void operator delete(void* memory,size_t size)
{
    s_AllocationMetrics.TotalFreed += size;
    PrintMemoryUsage();
    free(memory);
}


int main(int argc, char *argv[]) {
    //create SDL factory
    Abstract::Factory *AF = new SDL::SDLFactory();
    //initialise game class
    Game *g = Game::getInstance(AF);
    //run game
    g->run();

    //Deallocate memory
    Game::destroyGame();
    delete AF;
    std::cout << "Memory at the end of game: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
    return 0;
}
