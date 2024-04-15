#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>

bool abortProgram();
bool continueProgram();
void calculateSnakeHeadPosition(std::vector<int> &currPos, int ch);


extern std::vector<int> snakePosition;

bool receiveUserInput()
{
    int ch = 1;

    if ((ch = getch()) == ERR)
    {

    }
    else {
        switch(ch)
        {
        case 120:
            std::cout << "X" << std::endl;
            return abortProgram();
            break;
        default:
            calculateSnakeHeadPosition(snakePosition, ch);
        }
    }

    return continueProgram();
}

std::string render()
{
    // In work
    std::cout << "ReceiveUserInput Called.\n";
    return "Hello";
}

std::vector<int> getScreenSize()
{
    int y, x;
    getmaxyx(stdscr, y, x);
    return std::vector<int> {y, x};
}

bool checkWindowSizeEnough()
{
    auto hw = getScreenSize();
    return (hw.at(0) >= 10) && (hw.at(1) >= 10);
}

bool abortProgram()
{
    return false;
}

bool continueProgram()
{
    return true;
}

void printWhiteSpace(int y, int x)
{
    mvprintw(y, x, " ");
}

void printNewLine(int y, int x)
{
    mvprintw(y, x, "\n");
}

void renderBorder(int maxY, int maxX)
{
    for (int i = 0; i <= maxX-1; i++)
    {
        mvprintw(0, i, "#");
    }

    for (int i = 0; i < maxY-1; i++)
    {
        mvprintw(i,0,"#");
        mvprintw(i,maxX-1,"#");
    }

    for (int i = 0; i <= maxX-1; i++)
    {
        mvprintw(maxY-1, i, "#");
    }
}

void renderSnake(int y, int x)
{
    mvprintw(y, x, "O");
}

void calculateSnakeHeadPosition(std::vector<int> &currPos, int ch)
{
    int currX = currPos.at(1);
    int currY = currPos.at(0);
    switch(ch)
    {
        case 97:
            //A
            currPos.at(1) = currX-2;
            break;
        case 100:
            //D
            currPos.at(1) = currX+2;
            break;
        case 115:
            //S
            currPos.at(0) = currY+1;
            break;
        case 119:
            //W
            currPos.at(0) = currY-1;
            break;
        default:
            break;
    }
}
