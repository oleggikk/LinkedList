#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList();
    void add_front(int value);
    void add_back(int value);
    void add_at(int index, int value);
    void remove_front();
    void remove_back();
    void remove_at(int index);
    int find(int value);
    int find_at(int index);
    void print();
    int get_size();
};

#endif //LINKED_LIST_LINKEDLIST_H
