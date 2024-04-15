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
    // list_t *list = createList();

    // node_t *a = createNode(2, 3);
    // node_t *b = createNode(5,43);
    // node_t *c = createNode(59,23);
    // node_t *d = createNode(323,323);
    // node_t *f = createNode(222, 222);

    // pushBack(list, a);
    // pushBack(list, b);
    // pushBack(list, c);
    // pushBack(list, d);

    // printList(list);

    // pushNode(list, f, 1);
    // std::cout << list->size << std::endl;
    // std::cout << *(f->coords->at(0)) << " " << *(f->coords->at(1)) << std::endl;
    // printList(list);


    // popBack(list);
    // popBack(list);
    // popBack(list);
    // popBack(list);

    // list = freeList(list);

    // assert(NULL == list);

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
