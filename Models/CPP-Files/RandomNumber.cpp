//
// Created by cliff on 14/04/2020.
//

#include "../Headers/RandomNumber.h"
//seed random number generator
std::random_device GameNs::RandomNumber::m_rd;
GameNs::RandomNumber* GameNs::RandomNumber::m_instance = nullptr;

/**
 * Constructor
 */
GameNs::RandomNumber::RandomNumber() {}

GameNs::RandomNumber *GameNs::RandomNumber::getInstance() {
    if(m_instance== nullptr)
    {
        return m_instance = new RandomNumber();
    }
    return m_instance;
}

int GameNs::RandomNumber::getRandomNumber(int lowerBound, int higherBound) {
    std::mt19937 mt(m_rd());
    std::uniform_real_distribution<double> m_dist(lowerBound,higherBound);
    return m_dist(mt);
}
