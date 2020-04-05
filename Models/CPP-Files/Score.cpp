//
// Created by cliff on 05/04/2020.
//

#include "../Headers/Score.h"
/**
 * Constructor
 */
GameNs::Score::Score() {}

int GameNs::Score::getScores() {
    return m_score;
}

void GameNs::Score::setScores(int scores) {
    m_score = scores;
}
