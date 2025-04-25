#include "../Engine.h"

int main() {
    Engine engine("Sokoban", 640, 640, "assets/font.ttf", 24, "assets/move.wav");
    engine.clear({0, 0, 0, 255});
    engine.flip();
    SDL_Delay(2000);  // Show window for 2 seconds
    return 0;
}
