/**
 * Class for player score
 */

#ifndef PROJECT_SCORE_H
#define PROJECT_SCORE_H

namespace GameNs{
    class Score {
    public:
        Score();
        int getScores();
        void setScores(int scores);
        virtual void render()=0;
    private:
        int m_score=0;
    };
}



#endif //PROJECT_SCORE_H
