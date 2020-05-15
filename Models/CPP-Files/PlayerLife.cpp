#include "../Headers/PlayerLife.h"

/**
 * Constructor
 */
Abstract::PlayerLife::PlayerLife() {}
/**
 * Destructor
 */
Abstract::PlayerLife::~PlayerLife(){}
/**
 * Method that returns player life
 * @return player life
 */
int Abstract::PlayerLife::getPlayerLife() {
    return m_playerLife;
}

/**
 * Method that sets player life
 * @param life - player life
 */
void Abstract::PlayerLife::setPlayerLife(int life) {
    m_playerLife = life;
}
