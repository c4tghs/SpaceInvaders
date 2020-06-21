
#ifndef PROJECT_RANDOMNUMBER_H
#define PROJECT_RANDOMNUMBER_H

#include <random>

namespace Abstract{
    class RandomNumber {
    public:
        static RandomNumber& getInstance();
        double getRandomDouble(double min, double max);
        int getRandomInt(int min, int max);
    private:
        RandomNumber();
        static std::random_device m_rd;
        std::mt19937 m_mt;
    };
}



#endif //PROJECT_RANDOMNUMBER_H
