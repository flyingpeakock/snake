#pragma once
#include "snake.h"
#include <vector>

enum class cellData {
    snake, food, empty
};

class Game {
public:
    Game(int height, int width);
    void updateGrid();
    Snake snake;
    bool isPlaying();
private:
    std::array<int, 2> foodPos;
    std::vector<std::array<int, 2>> *snek;
    std::vector<std::vector<cellData>> grid;
    const int rows, cols;
    std::vector<std::vector<cellData>> makeGrid();
    bool hasFood();
    void placeFood();
    bool playing;
};