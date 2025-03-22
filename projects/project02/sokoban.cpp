#include <iostream>
#include <vector>
#include "sokoban.h"

Game::Game()
    : board{}, player1{1}, player2{2}
{
    board = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'P'){
                player1 = i;
                player2 = j;
            }
        }
    }
}

void Game::play(char move)
{
    int dx, dy;

    if(move == 'w'){
        dx = -1;
        dy = 0;
    }
    else if(move == 's'){
        dx = 1;
        dy = 0;
    }
    else if(move == 'a'){
        dx = 0;
        dy = -1;
    }
    else if(move == 'd'){
        dx = 0;
        dy = 1;
    }
    else{
        return;
    }

    int newPlayer1 = player1 + dx;
    int newPlayer2 = player2 + dy;

    if(board[newPlayer1][newPlayer2] == ' '){
        board[player1][player2] = ' ';
        board[newPlayer1][newPlayer2] = 'P';
        player1 = newPlayer1;
        player2 = newPlayer2;
    }
    else if(board[newPlayer1][newPlayer2] == 'B'){
        if(pushBox(newPlayer1, newPlayer2, dx, dy)){
            board[player1][player2] = ' ';
            board[newPlayer1][newPlayer2] = 'P';
            player1 = newPlayer1;
            player2 = newPlayer2;
        }
    }
}

bool Game::pushBox(int newPlayer1, int newPlayer2, int dx, int dy)
{
    int newBox1 = newPlayer1 + dx;
    int newBox2 = newPlayer2 + dy;

    if(board[newBox1][newBox2] == ' '){
        board[newPlayer1][newPlayer2] = ' ';
        board[newBox1][newBox2] = 'B';
        return true;
    }
    return false;
}

Game::Status Game::gameStatus() const
{
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'B'){
                return Status::IN_PROGRESS;
            }
        }
    }
    return Status::WIN;
}

std::vector<std::vector<char>> Game::getBoard() const
{
    return board;
}

