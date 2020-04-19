//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_RANDOMNUMBER_H
#define PROJECT_RANDOMNUMBER_H

#include <random>

namespace GameNs{
    class RandomNumber {
    public:
        static RandomNumber* getInstance();
        static int getRandomNumber(int lowerBound, int higherBound);
    private:
        static RandomNumber* m_instance;
        RandomNumber();
        static std::random_device m_rd;
    };
}



#endif //PROJECT_RANDOMNUMBER_H
