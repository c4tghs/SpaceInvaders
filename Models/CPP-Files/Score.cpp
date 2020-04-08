//
// Created by cliff on 05/04/2020.
//

#include "../Headers/Score.h"
/**
 * Constructor
 */
GameNs::Score::Score() {}

/**
 * Method that returns player score
 * @return - the score
 */
int GameNs::Score::getScores() {
    return m_score;
}

/**
 * Method that sets the player's score
 * @param scores - the plauer's current score
 */
void GameNs::Score::setScores(int scores) {
    m_score = scores;
}
