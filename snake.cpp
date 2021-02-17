#include "snake.h"

Snake::Snake() {
    head = new Segment(0, 0);
    tail = head;
    for (int i = 0; i < 3; i++) {
        tail = tail->grow();
        step();
    }
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

bool Snake::isAlive() {
    auto seg = head->getNext();
    do {
        if (seg->col == head->col && seg->row == head->row)
            return false;
        seg = seg->getNext();
    } while (seg);
    return true;
}

Segment *Snake::getHead() {
    return head;
}