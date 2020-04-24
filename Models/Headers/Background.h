//
// Created by cliff on 14/03/2020.
//
/**
 * Background class
 */
#ifndef PROJECT_BACKGROUND_H
#define PROJECT_BACKGROUND_H

namespace GameNs
{
    class Background {
    public:
        Background();
        virtual ~Background();
        virtual void render()=0;
    };
}



#endif //PROJECT_BACKGROUND_H
