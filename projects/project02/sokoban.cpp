#include "sokoban.h"
#include <vector>

Game::Game()
    : board{}, playerX{1}, playerY{1}  // Default position
{
    board = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'P', ' ', ' ', ' ', ' ', ' ', ' ', 'G', '#'},
        {'#', ' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
}

void Game::play(char move) {
    int dx = 0, dy = 0;
    //move player based on input
    if (move == 'w') dx = -1;
    else if (move == 's') dx = 1;
    else if (move == 'a') dy = -1;
    else if (move == 'd') dy = 1;
    else return;

    int newX = playerX + dx;
    int newY = playerY + dy;

    // Check if the move is into a wall
    if (board[newX][newY] == '#') return;

    // Check if moving into a box
    if (board[newX][newY] == 'B') {
        if (pushBox(newX, newY, dx, dy)) {
            board[playerX][playerY] = ' ';  // Clear old position
            board[newX][newY] = 'P';
            playerX = newX;
            playerY = newY;
        }
    }
    // Normal move into empty space or goal
    else if (board[newX][newY] == ' ' || board[newX][newY] == 'G') {
        board[playerX][playerY] = ' ';  // Clear old position
        board[newX][newY] = 'P';
        playerX = newX;
        playerY = newY;
    }
}

bool Game::pushBox(int boxX, int boxY, int dx, int dy) {
    int newBoxX = boxX + dx;
    int newBoxY = boxY + dy;

    if (board[newBoxX][newBoxY] == ' ' || board[newBoxX][newBoxY] == 'G') {
        board[newBoxX][newBoxY] = 'B'; // Move box
        board[boxX][boxY] = ' ';       // Clear old box position
        return true;
    }
    return false;  // Box can't be pushed
}

Game::Status Game::gameStatus() const {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'G') {
                return Status::IN_PROGRESS; // Game continues if any box is left
            }
        }
    }
    return Status::WIN;
}

std::vector<std::vector<char>> Game::getBoard() const {
    return board;
}
