#include <iostream>
#include "snake.h"

int main() {
    Snake snek;
    for (auto i = 0; i < 50; i++) {
        snek.eat();
        snek.step();
    }
    auto pos = snek.getPos();
    for (auto p : pos) {
        for (auto i : p) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}