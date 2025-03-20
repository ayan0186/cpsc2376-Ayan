#include <iostream>
#include "dots_boxes.cpp"


int main() 
{
   Game game;
   game.makeBoard();  // Initialize the board
   game.gameplay();  // Start the game and pass the game object to the gameplay function
   return 0;
}