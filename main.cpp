#include <iostream>
#include <bin/SDL2/include/SDL.h>
#include <bin/SDL2/lib/x64/SDL2.lib>
#include <bin/SDL2/lib/x64/SDL2main.lib>

int main()
{
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640*4,480*4,0,&window,&render);
    SDL_RenderSetScale(render,4,4);

    SDL_SetRenderDrawColor(render,0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_setRenderDrawcolor(renderer,255,255,255,255);
    SDL_RenderDrawPoint(renderer,640/2,480/2);

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);



    return 0;




}
