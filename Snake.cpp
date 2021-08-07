#include "Snake.h"

Snake::Snake() : gameOver{false}, scoure{0}, x{width / 2}, y{hight / 2}, lenth{0}
{
    srand(time(static_cast<unsigned int>(0)));
    fruitY = rand() % ((hight - 3) + 1);
    fruitX = rand() % ((width - 3) + 1);
}

void Snake::draw()
{
    system ("clear");
    for (int lines{1}; lines <= hight; ++lines)
    {
        for (int line{1}; line <= width; ++line)
        {
            if (lines == 1 || lines == hight || line == 1 || line == width)
                std::cout << "#";
            else if ((lines == y) && (line == x))
                std::cout << "O";
            else if ((fruitY == lines) && (fruitX == line))
                std::cout << "$";
            else
            {
                bool printed{false};
                for (int i{0}; i < lenth; ++i)
                {
                    if ((tailX[i] == line) && (tailY[i] == lines))
                    {
                        std::cout << "o";
                        printed = true;
                    }
                }
                if (!printed)
                {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Scoure: " <<  getScoure() << std::endl;
}

void Snake::input()
{
    int key_nr;
    char key;
    keyboard keyb;
    if(keyb.kbhit()) // boolean positive if key is pressed
    {
        key_nr = keyb.getch(); //return int
        key = key_nr; // get ascii char
        switch(key) // gets ascii val of key pressed
        {
            case 'A':
            case 'a':
                dir = LEFT;
                break;
            case 'D':
            case 'd':
                dir = RIGHT;
                break;
            case 'W':
            case 'w':
                dir = UP;
                break;
            case 'S':
            case 's':
                dir = DOWN;
                break;
            /*
            case 'x':
                gameOver = true;
                break;
            */
        }
    }
}

void Snake::logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i{1}; i < lenth; ++i)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
    //gameOver if it touch the wall
    if (x <= 1 || x >= width || y <= 1 || y >= hight)
        gameOver = true;

    // if it touch the wall not gameOver
  /*  if (x >= width) x = 1; else if (x <= 1) x = width - 1;
    if (y >= hight) y = 1; else if (y <= 1) y = hight - 1;
*/
    for (int i{0}; i < lenth; ++i)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        scoure += 10;
        fruitY = rand() % ((hight - 3) + 1);
        fruitX = rand() % ((width - 3) + 1);
        ++lenth;
    }
}

void Snake::sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
}

bool Snake::getStatus()
{
    return gameOver;
}

int Snake::getScoure()
{
    return scoure;
}
