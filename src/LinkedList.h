#ifndef DOUBLE_LINKES_LIST_H
#define DOUBLE_LINKES_LIST_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

typedef float value_type_t;
#define NO_VALUE []() -> std::vector<value_type_t>* { return nullptr; }()

typedef struct node
{
    struct node *next;
    struct node *prev;
    // y == .at(0) , x == .at(1)
    std::vector<value_type_t*>* coords;
} node_t;

typedef struct list
{
    node_t *front;
    node_t *back;
    uint32_t size;
} list_t;


node_t *createNode(const value_type_t x_value, const value_type_t y_value);
node_t *freeNode(node_t *node);
list_t *createList(void);
list_t *freeList(list_t *list);

void pushBack(list_t *list, node_t *node);
std::vector<value_type_t>*  popBack(list_t *list);

void pushFront(list_t *list, node_t *node);
std::vector<value_type_t>*  popFront(list_t *list);

std::vector<value_type_t>* popNode(list_t *list, uint32_t idx);
std::vector<value_type_t>* pushNode(list_t *list, node_t *node, uint32_t idx);
std::vector<value_type_t>* valueAtIdx(list_t *list, uint32_t idx);

void printList(const list_t *const list);



#endif // DOUBLE_LINKES_LIST_H
