#pragma once 
#include <vector>
#include <iostream>

class Game 
{
private: 
    std::vector<std::vector<char>> board;
    char player1;
    char player2;
    char current_player;
    int turn;

public:
    Game() : board{}, player1{'-'}, player2{'|'}, current_player{player1}, turn{1} 
    {
        board.resize(9, std::vector<char>(9, ' '));  // Initialize board with empty spaces
    }

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    void makeBoard();  // Declare makeBoard function to initialize/reset the board
    void gameplay();  // Declare gameplay function to start the game

    enum class winStatus {PLAYER_1, PLAYER_2, DRAW, IN_PROGRESS};
    winStatus gameStatus() const;
};