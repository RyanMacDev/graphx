#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
    std::vector<std::vector<int>> grid;
    int rows, cols;

public:
    Game(int rows, int cols);
    void initializeRandom();
    void update();
    const std::vector<std::vector<int>>& getGrid() const;
};

#endif

