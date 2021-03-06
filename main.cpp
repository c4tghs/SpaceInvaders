
#include <iostream>
#include "Factories/AbstractFactory.h"
#include "Factories/SDLFactory.h"
#include "Controllers/Headers/Game.h"

struct AllocationMetrics{
    uint32_t TotalAllocated =0;
    uint32_t TotalFreed =0;

    uint32_t CurrentUsage(){return TotalAllocated-TotalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

static void PrintMemoryUsage()
{
    std::cout << "Memory usage: " << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
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
    GameNs::AbstractFactory *AF = new SDLNs::SDLFactory();
    //initialise game class
    GameNs::Game *g = GameNs::Game::getInstance(AF);
    //run game
    g->run();

    //Deallocate memory
    delete g;
    delete AF;
    std::cout << "Memory at the end of game: " << s_AllocationMetrics.CurrentUsage() << std::endl;
    return 0;
}
