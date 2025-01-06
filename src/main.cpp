#include "game.h"
#include "renderer.h"

int main() {
    Game game(50, 50);         // 50x50 grid
    Renderer renderer(800, 800); // 800x800 window

    game.initializeRandom(); // Initialize with random cells

    while (!renderer.shouldClose()) {
        renderer.pollEvents();
        renderer.render(game);
        game.update(); // Apply Conway's rules
    }

    return 0;
}

