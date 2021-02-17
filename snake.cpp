#include "snake.h"

Snake::Snake() {
    head = new Segment(0, 0);
    tail = head;
    for (int i = 0; i < 3; i++)
        tail = tail->grow();
}

Snake::~Snake() {
    delete head;
}

void Snake::eat() {
    tail = tail->grow();
}

bool Snake::turn(Direction dir) {
    bool ret;
    switch (dir) {
        case Direction::up:
        ret = head->up();
        break;
        case Direction::down:
        ret = head->down();
        break;
        case Direction::left:
        ret = head->left();
        break;
        case Direction::right:
        ret = head->right();
        break;
    }
    return ret;
}

void Snake::step() {
    tail->move();
}

std::vector<std::array<int, 2>> Snake::getPos() {
    std::vector<std::array<int, 2>> ret;
    Segment *seg = head;
    do {
        ret.emplace_back(std::array<int, 2>({{seg->row, seg->col}}));
        seg = seg->getNext();
    } while (seg);
    return ret;
}