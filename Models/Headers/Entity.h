#ifndef PROJECT_ENTITY_H
#define PROJECT_ENTITY_H

namespace Abstract{
    class Entity {
    public:
        Entity(double xPos, double yPos, double width, double height);
        double getXPosition() const;
        double getYPosition() const;
        double getWidth() const;
        double getHeight() const;
        void moveEntity(double xPos, double yPos);

    protected:
        double m_xPos;
        double m_yPos;
        double m_width;
        double m_height;
    };

}


#endif //PROJECT_ENTITY_H
