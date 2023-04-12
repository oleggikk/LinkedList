#include "iostream"
#include "Node.h"
#include "LinkedList.h"


LinkedList::LinkedList() // Create new empty Linked List
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void LinkedList::add_front(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        { // if List is empty - newNode become both head and tail
            tail = newNode;
        }
        else
        {
            newNode->next = head;
        }

        head = newNode;
        size++;
    }

    void LinkedList::add_back(int value)
    {
        Node* newNode = new Node(value);

        if (tail == nullptr)
        { // if List is empty - newNode become both head and tail
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }

        tail = newNode;
        size++;
    }

    void LinkedList::add_at(int index, int value)
    {
        if (index < 0 || index > size)
        {
            std::cout << "Invalid index\n";
            return;
        }

        if (index == 0)
        {
            add_front(value);
            return;
        }

        if (index == size)
        {
            add_back(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        Node* previous = nullptr;

        for (int i = 0; i < index; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = newNode;
        newNode->next = current;
        size++;
    }

    void LinkedList::remove_front() {
        if (head == nullptr) {
            std::cout << "List is empty, here is nothing to delete.\n";
            return;
        }

        Node* current = head;
        head = head->next;
        delete current;
        size--;

        if (size == 0) {
            tail = nullptr;
        }
    }

    void LinkedList::remove_back() {
        if (tail == nullptr) {
            std::cout << "List is empty, here is nothing to delete.\n";
            return;
        }

        if (size == 1) {
            remove_front();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != tail) {
            previous = current;
            current = current->next;
        }

        delete tail;
        tail = previous;
        tail->next = nullptr;
        size--;
    }

    void LinkedList::remove_at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            remove_front();
            return;
        }

        if (index == size - 1) {
            remove_back();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
        size--;
    }

    int LinkedList::find(int value) {
        Node* current = head;
        int index = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }

            current = current->next;
            index++;
        }

        return -1;
    }

    int LinkedList::find_at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    void LinkedList::print()
    {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    int LinkedList::get_size()
    {
        return size;
    }
