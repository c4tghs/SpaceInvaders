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
        static double getRandomDouble(int min, int max);
        static int getRandomInt(int min, int max);
    private:
        static RandomNumber* m_instance;
        RandomNumber();
        static std::random_device m_rd;
    };
}



#endif //PROJECT_RANDOMNUMBER_H
