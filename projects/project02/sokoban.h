#pragma once 
#include <iostream>
#include <vector>

class Game
{
   public: 

   enum Status { IN_PROGRESS, WIN }; 

   Game(); 

   void play(char move); 
   Game::Status gameStatus() const;
   std::vector<std::vector<char>> getBoard() const;

   private:
   std::vector<std::vector<char>> board;
   int player1, player2;

   bool pushBox(int newPlayer1, int newPlayer2, int dx, int dy);

};