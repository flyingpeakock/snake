#include "snake.h"
#include <set>

Snake::Snake(int height, int width):
    rows(height), cols(width), foodEaten(0), dir(Direction::right) {
    // snake starts in top left going to the right
    for (int i = 0; i < 3; i++) {
        body.emplace_back(std::array<int, 2>({{0, i}}));
    }
}

bool Snake::step() {
    auto tail = body.back();
    for (auto i = body.size() - 1; i > 0; i--) {
        body[i] = body[i-1];
    }
    if (0 < foodEaten) {
        body.push_back(tail);
        foodEaten--;
    }
    auto head = body[0];
    auto row = head[0];
    auto col = head[1];
    if (Direction::up == dir) {
        if (0 < row)
            body[0][0]--;
        else
            body[0][0] = rows;
    }
    if (Direction::down == dir) {
        if (rows > row)
            body[0][0]++;
        else
            body[0][0] = 0;
    }
    if (Direction::left == dir) {
        if (0 < col)
            body[0][1]--;
        else
            body[0][1] == cols;
    }
    if (Direction::right == dir) {
        if (cols > col)
            body[0][1]++;
        else
            body[0][1] = 0;
    }
    return isAlive();
}

std::vector<std::array<int,2>> *Snake::snek() {
    return &body;
}

void Snake::eat(int value) {
    foodEaten += value;
}

void Snake::eat() {
    eat(1);
}

bool Snake::isAlive() {
    // Only needs to check if head collides as rest of body follows
    auto head = body[0];
    for (auto i = 1; i < body.size(); i++) {
        if (body[i] == head)
            return false;
    }
    return true;
}

void Snake::up() {
    if (Direction::down == dir)
        return;
    dir = Direction::up;
}
void Snake::down() {
    if (Direction::up == dir)
        return;
    dir = Direction::down;
}
void Snake::left() {
    if (Direction::right == dir)
        return;
    dir = Direction::left;
}
void Snake::right() {
    if (Direction::left == dir)
        return;
    dir = Direction::right;
}