#include "SDL/SDL.h"

int main( int argc, char* args[] )
{
    SDL_Surface* screen = NULL;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //Set up screen
    screen = SDL_SetVideoMode( 800, 480, 32, SDL_SWSURFACE );
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 128, 0));
    SDL_Flip(screen);

    SDL_Delay(2000);
    //Quit SDL
    SDL_Quit();

    return 0;
}
