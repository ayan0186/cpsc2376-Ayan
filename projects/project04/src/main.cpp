#include <SDL.h>
#include "game.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;

    const int CELL  = 48;
    const int ROWS  = 10;
    const int COLS  = 10;
    SDL_Window*   win = SDL_CreateWindow("Sokoban",
                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                          COLS*CELL, ROWS*CELL, 0);
    if (!win) { SDL_Quit(); return 1; }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!ren) { SDL_DestroyWindow(win); SDL_Quit(); return 1; }

    Game game;
    bool running = true;
    bool shownWin = false;               // track whether we’ve shown the win dialog
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_r:
                        game = Game();
                        shownWin = false;
                        break;
                    case SDLK_w: case SDLK_UP:
                        game.play('w');  break;
                    case SDLK_s: case SDLK_DOWN:
                        game.play('s');  break;
                    case SDLK_a: case SDLK_LEFT:
                        game.play('a');  break;
                    case SDLK_d: case SDLK_RIGHT:
                        game.play('d');  break;
                }
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        game.draw(ren, CELL);
        SDL_RenderPresent(ren);

        // Win‐screen dialog: pop up once when you first detect WIN
        if (!shownWin && game.gameStatus() == Game::WIN) {
            shownWin = true;
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_INFORMATION,
                "Congratulations!",
                "You won!",
                win
            );
        }
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
