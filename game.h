#pragma once
#include "snake.h"
#include <ncurses.h>

class Game {
    public:
    Game(size_t wait);
    ~Game();
    void play();

    private:
    size_t delay;
    Snake snake;
    int cols, rows;
    int foodRow, foodCol;
    void print();
    void placeFood();
    bool foodInSnake();
};