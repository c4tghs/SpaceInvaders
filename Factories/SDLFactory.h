/**
 * Header for SDLfactory
 */

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 940

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "AbstractFactory.h"
#include "../Controllers/Headers/ConfigHandler.h"

namespace SDLNs
{
    class SDLFactory:public GameNs::AbstractFactory {
    public:
        SDLFactory();
        ~SDLFactory()override;
        GameNs::PlayerShip* createPlayerShip(const char* playerShipPath) override;
        GameNs::EnemyShip* createEnemyShip(const char* enemyShipPath, int xPos, int yPos, GameNs::Timer* timer) override;
        GameNs::Background* createBackground() override;
        GameNs::Bullet* createBullet(const char* bulletPath, int xPos, int yPos, int width, int height) override;
        GameNs::Timer* createTimer() override;
        GameNs::Score* createScore() override;
        GameNs::PlayerLife* createPlayerLife() override;
        GameNs::Bonus* createBonus(const char* bonusImagePath, int xPos, int yPos, int width, int height) override;
        void render() override;
        bool isRunning() override;
        void createWindow(const char* title, int width, int height);
        void createRender();
        void setRunningState(bool state) override;


    private:
        bool m_isRunning = false;
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        GameNs::Timer* m_timer= nullptr;
        GameNs::ConfigHandler* m_configHandler = nullptr;
        int m_screenWidth = 0;
        int m_screenHeight =0;
    };
}



#endif //PROJECT_SDLFACTORY_H
