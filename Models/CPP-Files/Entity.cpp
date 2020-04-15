/**
 * CPP file entity class
 */

#include "../Headers/Entity.h"
/**
 * Constructor for Entity
 */
GameNs::Entity::Entity() {}
/**
 * Constructor for Entity
 * @param xPos - x position of entity
 * @param yPos - y position of entity
 * @param width - width of entity
 * @param height - height of entity
 */
GameNs::Entity::Entity(int xPos, int yPos, int width, int height):m_xPos(xPos), m_yPos(yPos), m_width(width),
                                                                  m_height(height) {
    m_height = height;
    m_width = width;
    m_yPos = yPos;
    m_xPos = xPos;
}
/**
 * Method that returns y position of entity
 * @return y position
 */
int GameNs::Entity::getYPosition() const {
    return m_yPos;
}
/**
 * Method that returns x position of entity
 * @return x position
 */
int GameNs::Entity::getXPosition() const {
    return m_xPos;
}
/**
 * Method that returns width of entity
 * @return width
 */
int GameNs::Entity::getWidth() const {
    return m_width;
}
/**
 * Method that returns height of entity
 * @return height
 */
int GameNs::Entity::getHeight() const {
    return m_height;
}
/**
 * Method that sets the x position of entity
 * @param xPos - x position of entity
 */
void GameNs::Entity::setXPosition(int xPos) {
    m_xPos = xPos;
}
/**
 * Method that sets the y position of entity
 * @param yPos - y position of entity
 */
void GameNs::Entity::setYPosition(int yPos) {
    m_yPos = yPos;
}

/**
 * Method that sets the height of entity
 * @param height
 */
void GameNs::Entity::setHeight(int height) {
    m_height = height;
}
/**
 * Method that sets the width of entity
 * @param width
 */
void GameNs::Entity::setWidth(int width) {
    m_width = width;
}
