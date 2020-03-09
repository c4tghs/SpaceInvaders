//
// Created by cliff on 08/03/2020.
//

#include <iostream>
#include "../Headers/Graphics.h"
#include "../Headers/TextureManager.h"

SDL_Texture* alien;
SDL_Rect srect,drect ;
//SDL_Rect drect;


Graphics::Graphics()
{

}
Graphics::~Graphics() {

}
/***
 *
 * @param title
 * @param width
 * @param height
 */
void Graphics::createWindow(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
}
/***
 *
 */
void Graphics::createRender() {
    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //SDL_RENDERER_PRESENTVSYNC = synchronisation
}
/***
 *
 * @return
 */
SDL_Renderer* Graphics::getRenderer()
{
    return m_renderer;
}
/**
 *
 * @return Boolean - if engine is running or not
 */
bool Graphics::initialise(){
    //check if SDL was initialised succesfully
    if(SDL_Init(SDL_INIT_VIDEO) !=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=0)
    {
        SDL_Log("Failed to initialise SDL: %s",SDL_GetError());
        return false;
    }
    //create SDL window
    createWindow("SDL engine",SCREEN_WIDTH,SCREEN_HEIGHT);

    //check if window was created successfully
    if(m_window == nullptr)
    {
        SDL_Log("Failed to create Window: %s",SDL_GetError());
        return false;
    }
    //create renderer
    createRender();

    //check if renderer was created succesfully
    if(m_renderer == nullptr)
    {
        SDL_Log("Failed to create Renderer: %s",SDL_GetError());
    }

    //create surface
    alien = TextureManager::LoadTexture("../assets/alien.jpg",m_renderer);

    return m_IsRunning = true;

}
/**
 *
 * @return
 */
bool Graphics::getRunningState() {
    return m_IsRunning;
}
/**
 * Method used to clean everything after user quits the game
 *
 */
void Graphics::Clean()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    cout << "Game cleaned succesfully" << endl;
}
void Graphics::Update(){
    //call player and enemy update functions

    if(m_rightDirection)
    {
        m_count++;
    } else
    {
        m_count --;
    }

    if(m_count >= 640)
    {
        m_rightDirection = false;
        //m_count --;
    }
    else if(m_count <= 0)
    {
        m_rightDirection = true;
    }

    //cout << m_count << endl;
    drect.h = 32;
    drect.w = 32;
    drect.x = m_count;

}
/**
 * Method used to set certain features of the renderer
 */
void Graphics::Render(){
    //clear renderer adding things
    SDL_RenderClear(m_renderer);
    //set background color
    SDL_SetRenderDrawColor(m_renderer,100,218,254,255);

    //show alien
    SDL_RenderCopy(m_renderer,alien,NULL,&drect); // srcrect: part of image that you want to draw. dstrect: where you want to draw image
    //present render
    SDL_RenderPresent(m_renderer);
}
/**
 * Method used to handle events
 */
void Graphics::Events()
{
    string keyboardInfo;
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            Quit();
            break;
        case SDL_KEYDOWN:
             keyboardInfo = event.key.keysym.sym;
             playerDirection(keyboardInfo);

    }
}
/**
 *
 */
void Graphics::Quit() {
    m_IsRunning = false;
}
void Graphics::playerDirection(string key)
{
    if(key == "P")
    {
        m_rightDirection = false;
    }
    else if(key == "O")
    {
        m_rightDirection = true;
    }
}