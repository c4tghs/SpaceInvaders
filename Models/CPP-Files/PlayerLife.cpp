//
// Created by cliff on 09/04/2020.
//

#include "../Headers/PlayerLife.h"

/**
 * Constructor
 */
GameNs::PlayerLife::PlayerLife() {}

/**
 * Method that returns playerlife
 * @return player life
 */
int GameNs::PlayerLife::getPlayerLife() {
    return m_playerLife;
}

/**
 * Method that sets player life
 * @param life - player life
 */
void GameNs::PlayerLife::setPlayerLife(int life) {
    m_playerLife = life;
}