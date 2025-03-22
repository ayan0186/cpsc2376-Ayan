#include "sokoban.h"
#include <iostream>

int main() {
    Game game;
    
    while (game.gameStatus() == Game::Status::IN_PROGRESS) {
         std::vector<std::vector<char>> board = game.getBoard();
         for (std::vector<std::vector<char>>::size_type i = 0; i < board.size(); i++) {
             for (std::vector<char>::size_type j = 0; j < board[i].size(); j++) {
                 std::cout << board[i][j];
             }
             std::cout << std::endl;
         }
        
        char move;
        std::cout << "Move (WASD): ";
        std::cin >> move;

        game.play(move);
    }

    std::cout << "You win!\n";
    return 0;
}
