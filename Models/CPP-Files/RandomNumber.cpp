//
// Created by cliff on 14/04/2020.
//

#include "../Headers/RandomNumber.h"

//seed random number generator
std::random_device GameNs::RandomNumber::m_rd;
//static member
GameNs::RandomNumber* GameNs::RandomNumber::m_instance = nullptr;

/**
 * Constructor
 */
GameNs::RandomNumber::RandomNumber() {}

/**
 * Method that creates and returns instance of RandomNumber or returns instance of RandomNumber
 * @return instance of RandomNumber
 */
GameNs::RandomNumber *GameNs::RandomNumber::getInstance() {
    if(m_instance== nullptr)
    {
        return m_instance = new RandomNumber();
    }
    return m_instance;
}
/**
 * Method that returns a random number between a range
 * @param lowerBound - lower limit of range
 * @param higherBound - upper limit of range
 * @return - generated number
 */
int GameNs::RandomNumber::getRandomNumber(int lowerBound, int higherBound) {
    std::mt19937 mt(m_rd());
    std::uniform_real_distribution<double> m_dist(lowerBound,higherBound);
    return m_dist(mt);
}
