/**
 * CPP file entity class
 */

#include "../Headers/Entity.h"

/**
 * Constructor for Entity
 * @param xPos - x position of entity
 * @param yPos - y position of entity
 * @param width - width of entity
 * @param height - height of entity
 */
Abstract::Entity::Entity(double xPos, double yPos, double width, double height){
    m_height = height;
    m_width = width;
    m_yPos = yPos;
    m_xPos = xPos;
}
/**
 * Method that returns y position of entity
 * @return y position
 */
double Abstract::Entity::getYPosition(){
    return m_yPos;
}
/**
 * Method that returns x position of entity
 * @return x position
 */
double Abstract::Entity::getXPosition(){
    return m_xPos;
}
/**
 * Method that returns width of entity
 * @return width
 */
double Abstract::Entity::getWidth() const {
    return m_width;
}
/**
 * Method that returns height of entity
 * @return height
 */
double Abstract::Entity::getHeight() const {
    return m_height;
}


/**
 * Method used to move entity
 * @param xPos - x position of entity
 * @param yPos - y position of entity
 */
void Abstract::Entity::moveEntity(double xPos, double yPos) {
    m_xPos = xPos;
    m_yPos = yPos;
}

