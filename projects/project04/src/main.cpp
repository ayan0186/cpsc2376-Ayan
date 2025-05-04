#include <SDL.h>
#include "game.h"

int main() {
    /* 1. Init SDL ---------------------------------------------------- */
    SDL_Init(SDL_INIT_VIDEO);
    const int CELL  = 48;
    const int ROWS  = 10;
    const int COLS  = 10;
    SDL_Window*   win = SDL_CreateWindow("Sokoban",
                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                          COLS*CELL, ROWS*CELL, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    /* 2. Objects ----------------------------------------------------- */
    Game game;

    /* 3. Main loop --------------------------------------------------- */
    bool running = true;
    SDL_Event e;
    while (running) {
        /* 3a. Events */
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)               running = false;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: running = false;            break;
                    case SDLK_r:      game = Game();              break;  // restart
                    case SDLK_w:
                    case SDLK_UP:     game.play('w');             break;
                    case SDLK_s:
                    case SDLK_DOWN:   game.play('s');             break;
                    case SDLK_a:
                    case SDLK_LEFT:   game.play('a');             break;
                    case SDLK_d:
                    case SDLK_RIGHT:  game.play('d');             break;
                }
            }
        }

        /* 3b. Draw */
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);  // black background
        SDL_RenderClear(ren);
        game.draw(ren, CELL);
        SDL_RenderPresent(ren);
    }

    /* 4. Clean up ---------------------------------------------------- */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
