#pragma once
#include <vector>
#include <array>
#include "segment.h"

class Snake {
    public:
    Snake();
    ~Snake();

    void eat(); // Calls grow on tail
    bool turn(Direction dir);
    void step();

    std::vector<std::array<int, 2>> getPos();

    private:
    Segment *head;
    Segment *tail;
};