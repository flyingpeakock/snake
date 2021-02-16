#include "game.h"
#include <stdlib.h>
#include <time.h>

Game::Game(int height, int width):
    rows(height), cols(width), snake(height, width), playing(true) {
    grid = makeGrid();
    snek = snake.snek();
    placeFood();
}

std::vector<std::vector<cellData>> Game::makeGrid() {
    std::vector<std::vector<cellData>> thisgrid;
    for (auto i = 0; i < rows; i++) {
        thisgrid.emplace_back(std::vector<cellData>());
        for (auto j = 0; j < cols; j++) {
            thisgrid.back().emplace_back(cellData::empty);
        }
    }
    for (auto seg : *snek) {
        thisgrid[seg[0]][seg[1]] = cellData::snake;
    }
    return thisgrid;
}

void Game::updateGrid() {
    if (!playing)
        return;
    if (!snake.step()) {
        playing = false;
    }
    if (snake.head() == foodPos) {
        snake.eat();
        placeFood();
    }
}

bool Game::isPlaying() {
    return playing;
}

void Game::placeFood() {
    srand(time(NULL)); // seed
    auto row = rand() % rows;
    auto col = rand() % cols;
    foodPos = {row, col};
    for (auto seg : *snek) {
        if (foodPos == seg)
            return placeFood(); // Recurse
    }
    grid[row][col] = cellData::food;
    return;
}