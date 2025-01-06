#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int rows, int cols) : rows(rows), cols(cols), grid(rows, std::vector<int>(cols, 0)) {}

void Game::initializeRandom() {
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
}

void Game::update() {
    std::vector<std::vector<int>> newGrid = grid;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int liveNeighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        liveNeighbors += grid[ni][nj];
                    }
                }
            }
            newGrid[i][j] = (grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) ||
                            (grid[i][j] == 0 && liveNeighbors == 3);
        }
    }
    grid = newGrid;
}

const std::vector<std::vector<int>>& Game::getGrid() const {
    return grid;
}

