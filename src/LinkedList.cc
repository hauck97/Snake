#include <iostream>
#include <cstdlib>
#include <vector>

#include "LinkedList.h"

node_t *createNode(const value_type_t x_value, const value_type_t y_value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (NULL == node)
    {
        return NULL;
    }

    value_type_t *p_value_x = (value_type_t *)malloc(sizeof(value_type_t));
    value_type_t *p_value_y = (value_type_t *)malloc(sizeof(value_type_t));


    if (NULL == p_value_x || NULL == p_value_y)
    {
        free(node);
        return NULL;
    }

    *p_value_x = x_value;
    *p_value_y = y_value;

    node->next = NULL;
    node->prev = NULL;

    std::vector<value_type_t*>* coords = new std::vector<value_type_t*>();
    node->coords = coords;
    node->coords->push_back(p_value_y);
    node->coords->push_back(p_value_x);

    return node;
}


node_t *freeNode(node_t *node)
{
    if (NULL == node)
    {
        return NULL;
    }

    delete node->coords;
    free(node);

    return NULL;
}

list_t *createList(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (NULL == list)
    {
        return NULL;
    }

    list->front = NULL;
    list->back = NULL;
    list->size = 0u;

    return list;
}

list_t *freeList(list_t *list)
{
    if (NULL == list)
    {
        return NULL;
    }

    free(list);
    return nullptr;
}


void pushBack(list_t *list, node_t *node)
{
    if (NULL == list || NULL == node)
    {
        return;
    }

    if (list->size > 0u)
    {
        node->next = NULL;
        node->prev = list->back;
        list->back->next = node;
        list->back = node;
    } else {
        node->next = NULL;
        node->prev = NULL;
        list->front = node;
        list->back = node;
    }
    list->size++;
}

std::vector<value_type_t>* popBack(list_t *list)
{
    if (NULL == list)
    {
        return NO_VALUE;
    }

    node_t* node = list->back;
    std::vector<value_type_t>* coords = new std::vector<value_type_t>();

    coords->push_back(*(node->coords->at(0)));
    coords->push_back(*(node->coords->at(1)));

    if(list->size > 1u)
    {
        list->back = node->prev;
        list->back->next = NULL;
    } else
    {
        list->back = NULL;
        list->front = NULL;
    }

    list->size--;
    node = freeNode(node);

    return coords;
}

void pushFront(list_t *list, node_t *node)
{
    std::cout << "PushFront" << std::endl;
    if (NULL == list || NULL == node)
    {
        return;
    }
    if (list->size > 0u)
    {
        node->prev = NULL;
        node->next = list->front;
        list->front->prev = node;
        list->front = node;
    } else {
        node->next = NULL;
        node->prev = NULL;
        list->front = node;
        list->back = node;
    }
    list->size++;
}

std::vector<value_type_t>* popFront(list_t *list)
{
    if (NULL == list)
    {
        return NO_VALUE;
    }

    node_t* node = list->front;
    std::vector<value_type_t>* coords = new std::vector<value_type_t>();

    coords->push_back(*(node->coords->at(0)));
    coords->push_back(*(node->coords->at(1)));

    if(list->size > 1u)
    {
        list->front = node->next;
        list->front->prev = NULL;
    } else
    {
        list->back = NULL;
        list->front = NULL;
    }

    list->size--;
    node = freeNode(node);

    return coords;
}

std::vector<value_type_t> *popNode(list_t *list, uint32_t idx)
{
    if (NULL == list || idx >= list->size)
    {
        return NO_VALUE;
    }

    if (0u == idx)
    {
        return popFront(list);
    }

    if ((list->size - 1u == idx))
    {
        return popBack(list);
    }

    uint32_t current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < idx)
    {
        node_at_idx = node_at_idx->next;
        current_idx++;
    }

    node_t *popped_node = node_at_idx;
    node_at_idx->next->prev = node_at_idx->prev;
    node_at_idx->prev->next = node_at_idx->next;

    list->size--;
    std::vector<value_type_t>* coords = new std::vector<value_type_t>();

    coords->push_back((*node_at_idx->coords->at(0)));
    coords->push_back((*node_at_idx->coords->at(1)));

    node_at_idx = freeNode(node_at_idx);

    return coords;
}

std::vector<value_type_t>* pushNode(list_t *list, node_t *node, uint32_t idx)
{
    if (NULL == list || NULL == node || idx >= list->size)
    {
        return NO_VALUE;
    }

    if (0u == idx)
    {
        pushFront(list, node);
    }

    if (list->size - 1u == idx)
    {
        pushBack(list, node);
    }

    uint32_t current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < idx)
    {
        node_at_idx = node_at_idx->next;
        current_idx++;
    }


    node->prev = node_at_idx;
    node->next = node_at_idx->next;
    node_at_idx->next->prev = node;
    node_at_idx->next = node;

    std::vector<value_type_t>* coords = new std::vector<value_type_t>();

    coords->push_back((*node_at_idx->coords->at(0)));
    coords->push_back((*node_at_idx->coords->at(1)));

    list->size++;

    return coords;
}

std::vector<value_type_t>* valueAtIdx(list_t *list, uint32_t idx)
{
     if (NULL == list || idx >= list->size)
    {
        return NO_VALUE;
    }

    if (0u == idx)
    {
        std::vector<value_type_t>* coords = new std::vector<value_type_t>();
        coords->push_back(*(list->front->coords->at(0)));
        coords->push_back(*(list->front->coords->at(1)));
        return coords;
    }

    if ((list->size - 1u == idx))
    {
        std::vector<value_type_t>* coords = new std::vector<value_type_t>();
        coords->push_back(*(list->back->coords->at(0)));
        coords->push_back(*(list->back->coords->at(1)));
        return coords;
    }

    uint32_t current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < list->size)
    {
        node_at_idx = node_at_idx->next;
        current_idx++;
    }

    std::vector<value_type_t>* coords = new std::vector<value_type_t>();

    coords->push_back((*node_at_idx->coords->at(0)));
    coords->push_back((*node_at_idx->coords->at(1)));

    return coords;
}

void printList(const list_t *const list)
{
    if (NULL == list)
    {
        return;
    }

    std::cout << "\nList contains " << list->size << " elements:\n" ;

    uint32_t current_idx = 0u;
    node_t *node_at_idx = list->front;
    std::cout << "\n";

    while(NULL != node_at_idx)
    {
        std::cout << "Node " << current_idx << ":"
                  << "\tY: " << *(node_at_idx->coords->at(0))
                  << "\tX: " << *(node_at_idx->coords->at(1))
                  << std::endl;
        node_at_idx = node_at_idx->next;
        current_idx++;
    }
}
