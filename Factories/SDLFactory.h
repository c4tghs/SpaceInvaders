/**
 * Header for SDLfactory
 */

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "AbstractFactory.h"
namespace SDLNs
{
    class SDLFactory:public GameNs::AbstractFactory {
    public:
        SDLFactory(){};

        GameNs::PlayerShip* createPlayerShip(std::string playerShipPath) override;
        GameNs::EnemyShip *createEnemyShip(std::string enemyShipPath, int xPos, int yPos) override;
        GameNs::Background* createBackground() override;
        GameNs::Bullet *createBullet(std::string bulletPath, int xPos, int yPos, int width, int height) override;
        GameNs::Timer* createTimer() override;
        GameNs::Score* createScore() override;
        GameNs::PlayerLife* createPlayerLife() override;
        GameNs::Bonus* createBonus(std::string bonusImagePath, int xPos, int yPos, int width, int height) override;
        void initialise(int windowWidth, int windowHeight) override;
        void close() override;
        void render() override;
        bool isRunning() override;
        void createWindow(const char* title,int width, int height);
        void createRender();

    private:
        bool m_isRunning = false;
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        int m_screenWidth = 0;
        int m_screenHeight =0;
    };
}



#endif //PROJECT_SDLFACTORY_H
