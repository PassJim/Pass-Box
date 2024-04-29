#include <iostream>
//#include <vector>
#include "SDL.h"

// Define a struct to represent a falling pixel


int main(int argc, char* argv[]) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

 // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

 // Main event loop
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    // Draw a white pixel at mouse position when left mouse button is pressed
                    int mouseX = e.button.x;
                    int mouseY = e.button.y;
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
                    SDL_RenderDrawPoint(renderer, mouseX, mouseY);
                    SDL_RenderPresent(renderer);
                }
            } else if (e.type == SDL_MOUSEMOTION) {
                if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    // Draw a white pixel at mouse position while left mouse button is held down
                    int mouseX = e.motion.x;
                    int mouseY = e.motion.y;
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
                    SDL_RenderDrawPoint(renderer, mouseX, mouseY);
                    SDL_RenderPresent(renderer);
                }
             } else if (e.type == SDL_MOUSEMOTION) {
                if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    // Draw a white pixel at mouse position while left mouse button is held down
                    int mouseX = e.motion.x;
                    int mouseY = e.motion.y;
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
                    SDL_RenderDrawPoint(renderer, mouseX, mouseY);
                    SDL_RenderPresent(renderer);
                }
             }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
