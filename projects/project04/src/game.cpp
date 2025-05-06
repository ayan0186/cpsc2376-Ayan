#include "game.h"
#include <SDL.h>

Game::Game()
    : playerX(1), playerY(1)
{
    board = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','P',' ',' ',' ',' ',' ',' ','G','#'},
        {'#',' ','B',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };
}

void Game::play(char move)
{
    int dx = 0, dy = 0;
    if (move == 'w')      dx = -1;
    else if (move == 's') dx =  1;
    else if (move == 'a') dy = -1;
    else if (move == 'd') dy =  1;
    else return;

    int newX = playerX + dx;
    int newY = playerY + dy;

    if (board[newX][newY] == '#') return;

    if (board[newX][newY] == 'B') {
        if (pushBox(newX, newY, dx, dy)) {
            board[playerX][playerY] = ' ';
            board[newX][newY] = 'P';
            playerX = newX;
            playerY = newY;
        }
    }
    else if (board[newX][newY] == ' ' || board[newX][newY] == 'G') {
        board[playerX][playerY] = ' ';
        board[newX][newY] = 'P';
        playerX = newX;
        playerY = newY;
    }
}

bool Game::pushBox(int boxX, int boxY, int dx, int dy)
{
    int newBoxX = boxX + dx;
    int newBoxY = boxY + dy;
    if (board[newBoxX][newBoxY] == ' ' || board[newBoxX][newBoxY] == 'G') {
        board[newBoxX][newBoxY] = 'B';
        board[boxX][boxY]     = ' ';
        return true;
    }
    return false;
}

Game::Status Game::gameStatus() const
{
    for (auto& row : board)
        for (char cell : row)
            if (cell == 'G')
                return IN_PROGRESS;
    return WIN;
}

std::vector<std::vector<char>> Game::getBoard() const
{
    return board;
}

void Game::draw(SDL_Renderer* ren, int cell) const
{
    SDL_Rect rect{0, 0, cell, cell};
    for (int r = 0; r < (int)board.size(); ++r) {
        for (int c = 0; c < (int)board[r].size(); ++c) {
            switch (board[r][c]) {
                case '#': SDL_SetRenderDrawColor(ren, 105,105,105,255); break;
                case 'P': SDL_SetRenderDrawColor(ren, 255,255,255,255); break;
                case 'B': SDL_SetRenderDrawColor(ren, 139,69,19,255);   break;
                case 'G': SDL_SetRenderDrawColor(ren,   0,255,  0,255); break;
                default:  SDL_SetRenderDrawColor(ren,   0,  0,  0,255); break;
            }
            rect.x = c * cell;
            rect.y = r * cell;
            SDL_RenderFillRect(ren, &rect);
        }
    }
}
