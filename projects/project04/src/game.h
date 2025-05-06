#pragma once
#include <vector>
#include <SDL.h>

class Game {
public:
    enum Status { IN_PROGRESS, WIN };

    Game();
    void play(char move);
    Status gameStatus() const;
    void draw(SDL_Renderer* ren, int cell) const;
    std::vector<std::vector<char>> getBoard() const;

private:
    std::vector<std::vector<char>> board;
    int playerX, playerY;
    bool pushBox(int boxX, int boxY, int dx, int dy);
};
