#include <iostream>

#include "Snake.h"

using namespace std;

int main()
{

    Snake snake{};

    while (!snake.getStatus())
    {
        snake.draw();
        snake.input();
        snake.logic();
        snake.sleep();
    }


    return 0;
}
