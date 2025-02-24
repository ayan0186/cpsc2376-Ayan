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
    gameplay(game);
    int playAgain;
    std::cout << "Do you want to play again? (1 for yes, 0 for no): ";
    std::cin >> playAgain;
    
    if(playAgain == 1){
        Connect_four game;
        game = Connect_four();
        gameplay(game);
        
    }else{
    std::cout << "Thanks for playing!" << std::endl;
    }
    return 0;
}