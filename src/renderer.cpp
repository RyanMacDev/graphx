#include "renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }

    window = glfwCreateWindow(width, height, "Game of Life", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(-1);
    }
}

Renderer::~Renderer() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Renderer::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Renderer::render(const Game& game) {
    glClear(GL_COLOR_BUFFER_BIT);

    const auto& grid = game.getGrid();
    int rows = grid.size();
    int cols = grid[0].size();

    float cellWidth = 2.0f / cols;
    float cellHeight = 2.0f / rows;

    glBegin(GL_QUADS);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                float x = -1.0f + j * cellWidth;
                float y = 1.0f - i * cellHeight;

                glVertex2f(x, y);
                glVertex2f(x + cellWidth, y);
                glVertex2f(x + cellWidth, y - cellHeight);
                glVertex2f(x, y - cellHeight);
            }
        }
    }
    glEnd();

    glfwSwapBuffers(window);
}

void Renderer::pollEvents() {
    glfwPollEvents();
}

