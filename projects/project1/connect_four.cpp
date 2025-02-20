#include <iostream>
#include <vector>
#include "connect_four.h"

// Function to create the board and display it
void Connect_four::makeBoard() {
    // Print the board after setting up or updating
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << "|" << board[i][j];  // Display each cell in the row
        }
        std::cout << "|" << std::endl;  // New line after each row
    }
    std::cout << std::endl;
}

// Function to play the game, alternating turns
void Connect_four::play() {
    while(gameStatus() == winStatus::IN_PROGRESS) {
        
    int c;  // Column chosen by the player
    bool valid = false;
    
    // Print who's turn it is
    std::cout << "Player " << current_player << "'s turn" << std::endl;
    std::cout << "Enter a column number (0 to " << col - 1 << "): ";
    
    while (!valid) {
        std::cin >> c;

        // Input validation for column number
        if (c < 0 || c >= col) {
            std::cout << "Invalid column number. Please try again: ";
        } else {
            // Find the lowest available row in the chosen column
            bool placed = false;
            for (int i = row - 1; i >= 0; --i) {
                if (board[i][c] == " ") {  // Find the first empty cell from the bottom
                    board[i][c] = (current_player == player1 ? "X" : "O");
                    placed = true;
                    valid = true;
                    break;
                }
            }

            // If the column is full, prompt the player again
            if (!placed) {
                std::cout << "Column is full. Please choose another column: ";
            }
        }
    }

    makeBoard();  // Display the board after a valid move

    // Change player turn after a valid move
    current_player = (current_player == player1 ? player2 : player1);
}
}
// Function to check the game status (win, draw, or in progress)
Connect_four::winStatus Connect_four::gameStatus() const {
    for(int i = row - 1; i >= 0; --i) {
        for(int j = 0; j < col; ++j) {
            if(board[i][j] == " ") {
                continue;
            }
            // Check horizontal
            if(j + 3 < col && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return (board[i][j] == "X" ? winStatus::PLAYER_1 : winStatus::PLAYER_2);
            }
            // Check vertical
            if(i - 3 >= 0 && board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j] && board[i][j] == board[i - 3][j]) {
                return (board[i][j] == "X" ? winStatus::PLAYER_1 : winStatus::PLAYER_2);
            }
            // Check diagonal (top-left to bottom-right)
            if(i - 3 >= 0 && j + 3 < col && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return (board[i][j] == "X" ? winStatus::PLAYER_1 : winStatus::PLAYER_2);
            }
            // Check diagonal (bottom-left to top-right)
            if(i + 3 < row && j + 3 < col && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return (board[i][j] == "X" ? winStatus::PLAYER_1 : winStatus::PLAYER_2);
            }
        }
    }

    // Check for a draw (no spaces left)
    bool full = true;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == " ") {
                full = false;
                break;
            }
        }
    }

    if (full) {
        return winStatus::DRAW;
    }

    return winStatus::IN_PROGRESS;
}
