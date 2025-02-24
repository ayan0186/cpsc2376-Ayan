#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H
#include <vector>
#include <iostream>
#include <string>

// Connect_four class declaration
class Connect_four
{
private:
    std::vector<std::vector<std::string>> board;
    int row; 
    int col; 
    std::string player1;
    std::string player2;
    std::string current_player; 
    int turn;
public:
    Connect_four(int r = 6, int c = 7)
        : board{}, row{r}, col{c}, player1{"X"}, player2{"O"}, current_player{player1}, turn{1}
    {
        board.resize(row, std::vector<std::string>(col, " "));
    }
    // Function declarations
    enum class winStatus {PLAYER_1, PLAYER_2, DRAW, IN_PROGRESS};

    void makeBoard();
    void play();
    winStatus gameStatus() const;
};

#endif