#include <iostream>
#include <vector>
#include "connect_four.cpp" 

void gameplay(Connect_four &game){
    game.makeBoard();
    game.play();

    if(game.gameStatus() == Connect_four::winStatus::IN_PROGRESS){
        return;
    }
    else
    
    if(game.gameStatus() == Connect_four::winStatus::PLAYER_1){
        std::cout << "Player 1 wins!" << std::endl;
        return;
    }
    else if(game.gameStatus() == Connect_four::winStatus::PLAYER_2){
        std::cout << "Player 2 wins!" << std::endl;
        return;
    }
    else if(game.gameStatus() == Connect_four::winStatus::DRAW){
        std::cout << "It's a draw!" << std::endl;
        return;
    }
    }

int main() {
    Connect_four game;
    
    while(true){
        gameplay(game);

        std::string playAgain;
        std::cout << "Would you like to play again? (yes/no): ";
        std::cin >> playAgain;
        if(playAgain == "yes"){
            game = Connect_four(); //reset the game
            continue;
        }
        else if(playAgain == "no"){
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else{
            std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
        }
    }
    return 0;
}