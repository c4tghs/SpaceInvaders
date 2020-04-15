/**
 * Entity class
 */

#ifndef PROJECT_ENTITY_H
#define PROJECT_ENTITY_H

namespace GameNs{
    class Entity {
    public:
        Entity();
        Entity(int xPos, int yPos, int width, int height);
        int getXPosition() const;
        void setXPosition(int xPos);
        void setYPosition(int yPos);
        int getYPosition() const;
        int getWidth() const;
        int getHeight() const;
        void setHeight(int height);
        void setWidth(int width);

    private:
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
    };

}


#endif //PROJECT_ENTITY_H
