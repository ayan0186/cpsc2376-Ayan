#include <iostream>
#include <vector>
#include "dots_boxes.h"

// Overloaded ostream operator for printing the board
std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            os << game.board[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

// Check if the game has a winner
bool Game::checkWin() const {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '-') {
                count++;
            }
        }
    }
    return count == 0;
}

// Check if the game is a draw
bool Game::checkDraw() const {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == ' ') {
                count++;
            }
        }
    }
    return count == 0;
}

// Switch between players
void Game::switchPlayer() {
    if (current_player == player1) {
        current_player = player2;
    } else {
        current_player = player1;
    }
}

// Return the current status of the game
Game::winStatus Game::gameStatus() const {
    if (checkWin()) {
        if (turn % 2 == 0) {
            return winStatus::PLAYER_2;
        } else {
            return winStatus::PLAYER_1;
        }
    } else if (checkDraw()) {
        return winStatus::DRAW;
    } else {
        return winStatus::IN_PROGRESS;
    }
}

// Function to reset the board
void Game::makeBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = ' ';  // Reset each cell to empty
        }
    }
}

// Gameplay function definition

void Game::gameplay() {
    this->makeBoard();  // Reset the board for a new game
    while (this->gameStatus() == Game::winStatus::IN_PROGRESS) {
        std::cout << *this;  // Display the current game state
        this->switchPlayer(); // Switch the turn to the other player
        // Implement additional gameplay logic, e.g., taking turns, updating the board, etc.
    }
    std::cout << *this; // Print the final board state

    if (this->gameStatus() == Game::winStatus::PLAYER_1) {
        std::cout << "Player 1 wins!" << std::endl;
    } else if (this->gameStatus() == Game::winStatus::PLAYER_2) {
        std::cout << "Player 2 wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    int playAgain;
    std::cout << "Do you want to play again? (1 for yes, 0 for no): ";
    std::cin >> playAgain;

    if (playAgain == 1) {
        Game newGame;  // Create a new game instance for a fresh start
        newGame.gameplay();  // Call gameplay for the new game
    } else {
        std::cout << "Thanks for playing!" << std::endl;
    }
}
