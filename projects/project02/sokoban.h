#pragma once
#include <vector>

class Game {
public:
    enum Status { IN_PROGRESS, WIN };

    Game(); 
    void play(char move);
    Status gameStatus() const;
    std::vector<std::vector<char>> getBoard() const;

private:
    std::vector<std::vector<char>> board;
    int playerX, playerY;
    bool pushBox(int boxX, int boxY, int dx, int dy);
};
