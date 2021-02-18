#pragma once

// basically a specialized doubly linked list

enum class Direction {
    up, down, left, right
};

class Segment {
    public:
    Segment(int y, int x); // Constructor for head
    Segment(Segment *s); // Constructor tail
    ~Segment();
    
    int row, col;
    void move(); // call on tail
    Segment* grow(); // returns a pointer to the last segment
    
    // returns false if direction did not change
    // e.g. if trying to go left when going right
    // or trying to go right when already going right
    bool up();
    bool down();
    bool right();
    bool left();
    Segment *getNext();

    private:
    Segment *next;
    Segment *prev;
    Direction dir;
};
