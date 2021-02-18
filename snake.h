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

    int score();
    
    bool isAlive();

    Segment* getHead();

    private:
    int length;
    Segment *head;
    Segment *tail;
};