#include "sokoban.cpp"
#include <iostream>

int main() {
    Game game;

    while (game.gameStatus() == Game::Status::IN_PROGRESS) {
        std::vector<std::vector<char>> board = game.getBoard();

        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell;
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
