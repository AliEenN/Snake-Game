#ifndef SNAKE_H
#define SNAKE_H

#include <thread>
#include <random>
#include <iostream>

#include "kbhit.h"

class Snake
{

const int width{80};
const int hight{40};

enum eDireection{STOP = 0, LEFT, RIGHT, UP, DOWN};

public:
    Snake();

    void draw();

    void input();

    void logic();

    void sleep();

    bool getStatus();

    int getScoure();


private:
    bool gameOver;
    int scoure;
    int x;
    int y;
    int fruitX;
    int fruitY;
    eDireection dir;
    int tailX[100];
    int tailY[100];
    int lenth;

};

#endif // SNAKE_H
