//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_RANDOMNUMBER_H
#define PROJECT_RANDOMNUMBER_H

#include <random>

namespace Abstract{
    class RandomNumber {
    public:
        static RandomNumber& getInstance();
        static double getRandomDouble(int lowerBound, int higherBound);
        static int getRandomInt(int lowerBound, int higherBound);
    private:
        RandomNumber();
        static std::random_device m_rd;
    };
}



#endif //PROJECT_RANDOMNUMBER_H
