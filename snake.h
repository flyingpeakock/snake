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
    
    bool isAlive();

    Segment* getHead();

    private:
    Segment *head;
    Segment *tail;
};