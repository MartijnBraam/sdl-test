#include "SDL/SDL.h"

int main( int argc, char* args[] )
{
    SDL_Surface* screen = NULL;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //Set up screen
    screen = SDL_SetVideoMode( 480, 800, 32, SDL_SWSURFACE );
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 128, 0));
    SDL_Flip(screen);

    bool quit = false;
    SDL_Event event;

    float keyboardPosition = 0;
    float keyboardTargetPosition = 1;

    auto keyboardColor = SDL_MapRGB(screen->format, 30, 30, 30);

    while(quit == false){
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 128, 0));

      if (SDL_PollEvent(&event)) {
        /* an event was found */
        switch (event.type) {
          /* close button clicked */
          case SDL_QUIT:
            quit = true;
            break;

          /* handle the keyboard */
          case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
              case SDLK_ESCAPE:
              case SDLK_q:
                quit = true;
                break;
            }
            break;
        }

    }

      if(keyboardPosition != keyboardTargetPosition){
        if(keyboardPosition > keyboardTargetPosition){
          keyboardPosition -= 0.01;
        }else{
          keyboardPosition += 0.01;
        }
        SDL_Rect keyboardRect;
        keyboardRect.x=0;
        keyboardRect.y=800-(int)(400*keyboardPosition);
        keyboardRect.w=480;
        keyboardRect.h=400;
        SDL_FillRect(screen, &keyboardRect, keyboardColor);

      }
      SDL_Flip(screen);
    }

    SDL_Delay(2000);
    //Quit SDL
    SDL_Quit();

    return 0;
}
