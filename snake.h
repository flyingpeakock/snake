#pragma once
#include <vector>
#include <array>

enum class Direction {
    up, down, left, right
};

class Snake {
public:
    Snake(int height, int width);
    bool step();
    void up();
    void down();
    void left();
    void right();
    void eat(int value);
    void eat();
private:
    const int rows;
    const int cols;
    Direction dir;
    std::vector<std::array<int, 2>> body;
    bool isAlive();
    int foodEaten;
};