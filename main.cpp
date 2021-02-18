#include <iostream>
#include "game.h"

int main(int argc, char *argv[]) {
     size_t delay = 100;
     if (argc == 2 && atoi(argv[1]) > 0) {
          delay = atoi(argv[1]);
     }
     Game game(delay);
     game.play();
}