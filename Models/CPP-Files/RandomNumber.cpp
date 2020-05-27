#include "../Headers/RandomNumber.h"

//Initialisation of static member
std::random_device Abstract::RandomNumber::m_rd;

/**
 * Method that returns instance of Random number
 * @return - object that represents random number
 */
Abstract::RandomNumber& Abstract::RandomNumber::getInstance() {
    static RandomNumber m_instance;
    return m_instance;
}

/**
 * Constructor
 */
Abstract::RandomNumber::RandomNumber() {}

/**
 * Method that returns a random number between a range
 * @param min - lower limit of range
 * @param max - upper limit of range
 * @return - double representing the generated number
 */
double Abstract::RandomNumber::getRandomDouble(int min, int max) {
    std::mt19937 mt(m_rd());
    //[min,max[
    std::uniform_real_distribution<double> m_dist(min, max);
    return m_dist(mt);
}

/**
 * Method that returns a random number between a range
 * @param min - lower limit of range
 * @param max - upper limit of range
 * @return - integer representing the generated number
 */
int Abstract::RandomNumber::getRandomInt(int min, int max) {
    std::mt19937 mt(m_rd());

    //HigherBound -1 because otherwise it is included
    //[min,max]
    std::uniform_int_distribution<int> m_dist(min, max - 1);
    return m_dist(mt);
}




