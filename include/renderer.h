#ifndef RENDERER_H
#define RENDERER_H

#include "game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
    GLFWwindow* window;

public:
    Renderer(int width, int height);
    ~Renderer();
    bool shouldClose() const;
    void render(const Game& game);
    void pollEvents();
};

#endif

