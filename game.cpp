#include "game.h"
#include <locale.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <time.h>

Game::Game() {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    getmaxyx(stdscr, rows, cols);
    delay = 100;
}

Game::~Game() {
    endwin();
}

void Game::play() {
    // placing food first
    placeFood();
    while (snake.isAlive()) {
        int ch = getch();
        switch(ch) {
            case KEY_UP:
            case 'k':
            case 'w':
            snake.turn(Direction::up);
            break;
            case KEY_DOWN:
            case 'j':
            case 's':
            snake.turn(Direction::down);
            break;
            case KEY_LEFT:
            case 'h':
            case 'a':
            snake.turn(Direction::left);
            break;
            case KEY_RIGHT:
            case 'l':
            case 'd':
            snake.turn(Direction::right);
            break;
            case 'q':
            case 27: // escape key
            return;
        }
        print();
        // should eat if has food since will print at 0,0 otherwise
        if (foodInSnake()) {
            snake.eat();
            placeFood();
        }
        snake.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Game::print() {
    clear();
    //mvprintw(foodRow, foodCol, "∙");
    auto seg = snake.getHead();
    if (seg->row < 0)
        seg->row = rows - 1;
    if (seg->row >= rows)
        seg->row = 0;
    if (seg->col < 0)
        seg->col = cols/2 - 1;
    if (seg->col >= cols/2)
        seg->col = 0;
    while(seg) {
        mvprintw(seg->row, seg->col*2, "██");
        seg = seg->getNext();
    }
    move(foodRow, foodCol);
    refresh();
}

void Game::placeFood() {
    srand(time(NULL));
    int row = rand() % rows;
    int col = rand() % cols;
    foodRow = row;
    foodCol = col;
    if (foodInSnake())
        return placeFood();
    return;
}

bool Game::foodInSnake() {
    auto seg = snake.getHead();
    while (seg) {
        if (foodRow == seg->row && foodCol/2 == seg->col)
            return true;
        seg = seg->getNext();
    }
    return false;
}