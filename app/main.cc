#include <iostream>
#include "snake.h"
#include <unistd.h>
#include <ncurses.h>
#include <vector>
#include <assert.h>
#include "LinkedList.h"

extern std::vector<int> snakePosition;

int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    std::cout << "Willkommen zu Snake!\n";

    bool isNotAborted = true;

    auto hw = getScreenSize();

    int maxY = hw.at(0);
    int maxX = hw.at(1);

    snakePosition.push_back(maxY/2);
    snakePosition.push_back(maxX/2);

    while((isNotAborted = receiveUserInput()) && checkWindowSizeEnough())
    {
        clear();

        renderBorder(maxY, maxX);
        renderSnake(snakePosition.at(0), snakePosition.at(1));

        refresh();
        usleep(20000);
    }

    endwin();

	return 0;
}
