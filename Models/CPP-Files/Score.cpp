//
// Created by cliff on 05/04/2020.
//

#include "../Headers/Score.h"

/**
 * Constructor
 */
Abstract::Score::Score() {
    m_score = 0;
}

/**
 * Destructor
 */
Abstract::Score::~Score() {}

/**
 * Method that returns player score
 * @return - the score
 */
int Abstract::Score::getScores() {
    return m_score;
}

/**
 * Method that sets the player's score
 * @param scores - the player's current score
 */
void Abstract::Score::setScores(int scores) {
    m_score = scores;
}
