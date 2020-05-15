#include <iostream>
#include "../Headers/SDLWindow.h"

/**
 * Constructor
 */
SDL::SDLWindow::SDLWindow(const char *title, int screenWidth, int screenHeight) : m_textureManager(nullptr) {
    //m_instance = nullptr;
    m_title = title;
    m_windowHeight = screenHeight;
    m_windowWidth = screenWidth;
    m_window = nullptr;
    m_renderer= nullptr;
}

/**
 * Destructor
 */
SDL::SDLWindow::~SDLWindow() {
    //Destory fonts
    TTF_CloseFont(m_font);

    delete m_textureManager;
    //Destroy Renderer
    SDL_DestroyRenderer(m_renderer);

    //Destory Window
    SDL_DestroyWindow(m_window);

    for(auto& iter: sounds)
    {
        //free chunk
        Mix_FreeChunk(iter.second);
    }
    //close sound
    Mix_CloseAudio();
    Mix_Quit();


    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * Method used to initialise the window
 * @return boolean indicating if window was initialised
 */
bool SDL::SDLWindow::initialise()
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) !=0)
    {
        std::cerr << "Failed to initialise SDL: "<< SDL_GetError() << "\n";
        return false;
    }
    //Check if TTF was initialised successfully
    else if (TTF_Init() < 0)
    {
        std::cerr << "Unable to initialise TTF library: "<< TTF_GetError() << "\n";
        return false;
    }
    else
    {
        //Create window
        m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
        //Check if window was created successfully
        if(m_window == nullptr)
        {
            std::cerr << "Failed to create Window." << "\n";
            return false;
        }
        else
        {
            //Create renderer
            m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            //Check if renderer was created successfully
            if(m_renderer == nullptr)
            {
                std::cerr << "Failed to create Renderer."<< "\n";
                return false;
            }
            else
            {
                //Texture manager
                m_textureManager = new TextureManager(m_renderer);

                //Initialise PNG, JPG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cerr << "Failed to initialise SDL_image: "<< IMG_GetError() << "\n";
                    return false;
                }

                //Initialise TTF
                if(TTF_Init() < 0)
                {
                    std::cerr << "Unable to initialise TTF library: "<< TTF_GetError() << "\n";
                    return false;
                }

                //Initialise Mixer
                if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,2048) <0)
                {
                    std::cerr << "Unable to initialise Mixer: "<< Mix_GetError() << "\n";
                    return false;
                }
            }

        }
    }
    return true;
}

/**
 * Update screen
 */
void SDL::SDLWindow::render() {
    SDL_RenderPresent(m_renderer);
}

/**
 * Method to load media, ie images, sounds, font
 * @return boolean representing successfulness
 */
bool SDL::SDLWindow::loadMedia() {
    //Background
    SDL_Surface* backgroundSurface = IMG_Load("../assets/background.png");
    if(backgroundSurface == nullptr)
    {
        std::cout << "Could not load background image. " << IMG_GetError() << "\n";
        return false;
    }
    else
    {
        m_background = SDL_CreateTextureFromSurface(m_renderer,backgroundSurface);
        if(m_background == nullptr)
        {
            std::cout << "Could not create back ground. " << SDL_GetError() << "\n";
        }
        SDL_FreeSurface(backgroundSurface);
    }

    if(m_textureManager->loadTexture("../assets/invader_sprites.png"))
    {
        //load sprite
        //Octopus
        //octopus closed 315,35,45,45
        //octopus open 257,35,45,35

        m_sprites[ENEMY_BIG].x = 315;
        m_sprites[ENEMY_BIG].y = 35;
        m_sprites[ENEMY_BIG].w = 45;
        m_sprites[ENEMY_BIG].h = 45;
        //Crab
        //crab 126,35,45,35
        //crab 186 35 45 35
        m_sprites[ENEMY_MEDIUM].x = 126;
        m_sprites[ENEMY_MEDIUM].y = 35;
        m_sprites[ENEMY_MEDIUM].w = 45;
        m_sprites[ENEMY_MEDIUM].h = 35;

        //Squid
        //squid 64 35 30 35
        //squid 6 35 30 35
        m_sprites[ENEMY_SMALL].x = 64;
        m_sprites[ENEMY_SMALL].y = 35;
        m_sprites[ENEMY_SMALL].w = 30;
        m_sprites[ENEMY_SMALL].h = 35;

        m_sprites[UFO].x = 382;
        m_sprites[UFO].y = 33;
        m_sprites[UFO].w = 86;
        m_sprites[UFO].h= 38;

        m_sprites[PLAYERSHIP].x = 492;
        m_sprites[PLAYERSHIP].y = 40;
        m_sprites[PLAYERSHIP].w = 48;
        m_sprites[PLAYERSHIP].h= 30;

        m_sprites[INVADER_DEATH].x = 555;
        m_sprites[INVADER_DEATH].y = 107;
        m_sprites[INVADER_DEATH].w = 48;
        m_sprites[INVADER_DEATH].h= 30;
    }
    else
    {
        return false;
    }

    //player shoot sound
    sounds[SHOOT] = Mix_LoadWAV("../assets/Sounds/player.wav");
    if(sounds[SHOOT] == nullptr)
    {
        std::cerr << "Could not load player shoot sound effect: " << Mix_GetError() << "\n";
        return false;
    }

    //enemy shoot sound
    sounds[HIT] = Mix_LoadWAV("../assets/Sounds/enemy.wav");
    if(sounds[HIT] == nullptr)
    {
        std::cerr << "Could not load enemy shoot sound effect: " << Mix_GetError() << "\n";
        return false;
    }

    //invader killed sound
    sounds[INVADER_KILLED] =Mix_LoadWAV("../assets/Sounds/invader_killed.wav");
    if(sounds[INVADER_KILLED] == nullptr)
    {
        std::cerr << "Could not load enemy killed sound effect: " << Mix_GetError() << "\n";
        return false;
    }


    //font
    m_font = TTF_OpenFont("../assets/Fonts/impact.ttf",32);
    if(m_font == nullptr)
    {
        std::cerr << "Unable to create font: "<< TTF_GetError() << "\n";
        return false;
    }

    SDL_RenderClear(m_renderer);
    //Show background
    //SDL_RenderCopy(m_renderer,m_background,nullptr,nullptr);
    return true;
}

/**
 * Method to render Rect
 * @param sprite  - the sprite type to render
 */
void SDL::SDLWindow::drawRect(SPRITE sprite, double xPos, double yPos, double width, double height) {

    m_textureManager->renderTexture(xPos,yPos,width,height,&m_sprites[sprite]);
}

/**
 * Method that returns window width
 * @return int representing window width
 */
int SDL::SDLWindow::getWindowWidth() {
    return m_windowWidth;
}

/**
 * Method that returns window height
 * @return int representing window height
 */
int SDL::SDLWindow::getWindowHeight() {
    return m_windowHeight;
}

void SDL::SDLWindow::refresh() {
    SDL_RenderClear(m_renderer);
    //Show background
    SDL_RenderCopy(m_renderer,m_background,nullptr,nullptr);
}

/**
 * Method to player a sound
 * @param sound - the sound to play
 */
void SDL::SDLWindow::playSound(SOUND_TYPE sound) {
    //-1: choose appropriate channel
    Mix_PlayChannel(-1,sounds[sound],0);
}



