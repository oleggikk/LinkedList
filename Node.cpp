#include <iostream>

class Node { // Element of Linked List, include data, ptr to next elem
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};