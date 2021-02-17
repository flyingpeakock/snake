#include "segment.h"

Segment::Segment(int y, int x): row(y), col(x) {
    next = nullptr;
    prev = nullptr;
    dir = Direction::right;
}

Segment::Segment(Segment *s) {
    next = nullptr;
    prev = s;
}

Segment::~Segment() {
    if (next) {
        delete next;
    }
}

void Segment::move() {
    /*
    call this function on the last element.
    sets row and col to that of previous, then recurses
    on previous until head is reached
    */
    if (!prev) {
        // Is the head, move in direction dir;
        switch (dir) {
            case Direction::up:
            row--;
            break;
            case Direction::down:
            row++;
            break;
            case Direction::right:
            col++;
            break;
            case Direction::left:
            col--;
            break;
        }

        return;
    }
    row = prev->row;
    col = prev->col;
    return prev->move();
}

Segment *Segment::grow() {
    /* 
    call this function on any segment
    faster if called on last
    */
    if (next)
        return next->grow();
    next = new Segment(this);
    return next;
}

bool Segment::up() {
    if (prev)
        return prev->up();
    if (dir == Direction::up || dir == Direction::down)
        return false;
    dir = Direction::up;
    return true;
}

bool Segment::down() {
    if (prev)
        return prev->down();
    if (dir == Direction::down || dir == Direction::up)
        return false;
    dir = Direction::down;
    return true;
}

bool Segment::left() {
    if (prev)
        return prev->left();
    if (dir == Direction::left || dir == Direction::right)
        return false;
    dir = Direction::left;
    return true;
}

bool Segment::right() {
    if (prev)
        return prev->right();
    if (dir == Direction::right || dir == Direction::left)
        return false;
    dir = Direction::right;
    return true;
}

Segment *Segment::getNext() {
    return next;
}