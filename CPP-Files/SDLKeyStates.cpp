//
// Created by cliff on 14/03/2020.
//

#include "../Headers/SDLKeyStates.h"
SDLKeyStates::SDLKeyStates(){}
int SDLKeyStates::directions() {
    SDL_Event event;
    SDL_PollEvent(&event);

  const  Uint8* keystate = SDL_GetKeyboardState(NULL);
  if(keystate[SDL_SCANCODE_LEFT])
  {
      return 1;
  }
  else if(keystate[SDL_SCANCODE_RIGHT]){
      return 2;
  };
  return  0;
}