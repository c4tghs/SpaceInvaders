/**
 * Header for SDLfactory
 */

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../Models/Headers/Ship.h"
#include "AbstractFactory.h"
namespace SDLNs
{
    class SDLFactory:public GameNs::AbstractFactory {
    public:
        SDLFactory(){};

        GameNs::Ship* createPlayerShip(std::string playerShipPath) override;
        GameNs::Ship *createEnemyShip(std::string enemyShipPath, int xPos, int yPos) override;
        GameNs::Background* createBackground() override;
        GameNs::Bullet* createBullet(std::string bulletPath, int xPos, int yPos) override;
        GameNs::Timer* createTimer() override;
        GameNs::Score* createScore() override;
        void createWindow(const char* title,int width, int height);
        void createRender();
        void initialise(int windowWidth, int windowHeight) override;
        void close() override;
        void render() override;
        bool getRunningState() override;

    private:
        bool m_IsRunning = false;
        SDL_Window *m_window = nullptr;
        SDL_Renderer *m_renderer = nullptr;

        int m_screenWidth = 0;
        int m_screenHeight =0;
    };
}



#endif //PROJECT_SDLFACTORY_H
