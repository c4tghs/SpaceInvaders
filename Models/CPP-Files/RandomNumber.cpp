#include "../Headers/RandomNumber.h"

//seed for random number generator
std::random_device Abstract::RandomNumber::m_rd;

/**
 * Constructor
 */
Abstract::RandomNumber::RandomNumber() {}

/**
 * Method that creates and returns instance of RandomNumber or returns instance of RandomNumber
 * @return instance of RandomNumber
 */
Abstract::RandomNumber& Abstract::RandomNumber::getInstance() {
    static RandomNumber m_instance;
    return m_instance;
}
/**
 * Method that returns a random number between a range
 * @param lowerBound - lower limit of range
 * @param higherBound - upper limit of range
 * @return - double representing the generated number
 */
double Abstract::RandomNumber::getRandomDouble(int lowerBound, int higherBound) {
    std::mt19937 mt(m_rd());
    std::uniform_real_distribution<double> m_dist(lowerBound,higherBound);
    return m_dist(mt);
}

/**
 * Method that returns a random number between a range
 * @param lowerBound - lower limit of range
 * @param higherBound - upper limit of range
 * @return - integer representing the generated number
 */
int Abstract::RandomNumber::getRandomInt(int lowerBound, int higherBound) {
    std::mt19937 mt(m_rd());
    //HigherBound -1 because otherwise it is included
    std::uniform_int_distribution<int> m_dist(lowerBound,higherBound-1);
    return m_dist(mt);
}


