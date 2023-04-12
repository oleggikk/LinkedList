#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList myList;

    int choice, value, index;

    while (true) {
        std::cout << "1. Add front\n";
        std::cout << "2. Add back\n";
        std::cout << "3. Add at\n";
        std::cout << "4. Remove front\n";
        std::cout << "5. Remove back\n";
        std::cout << "6. Remove at\n";
        std::cout << "7. Find value\n";
        std::cout << "8. Find at\n";
        std::cout << "9. Print\n";
        std::cout << "10. Size\n";
        std::cout << "11. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to add: ";
                std::cin >> value;
                myList.add_front(value);
                break;
            case 2:
                std::cout << "Enter the value to add: ";
                std::cin >> value;
                myList.add_back(value);
                break;
            case 3:
                std::cout << "Enter the index: ";
                std::cin >> index;
                std::cout << "Enter the value to add: ";
                std::cin >> value;
                myList.add_at(index, value);
                break;
            case 4:
                myList.remove_front();
                break;
            case 5:
                myList.remove_back();
                break;
            case 6:
                std::cout << "Enter the index: ";
                std::cin >> index;
                myList.remove_at(index);
                break;
            case 7:
                std::cout << "Enter the value to find: ";
                std::cin >> value;
                index = myList.find(value);

                if (index == -1) {
                    std::cout << "Value not found\n";
                } else {
                    std::cout << "Value found at index " << index << "\n";
                }

                break;
            case 8:
                std::cout << "Enter the index: ";
                std::cin >> index;
                value = myList.find_at(index);

                if (value == -1) {
                    std::cout << "Invalid index\n";
                } else {
                    std::cout << "Value at index " << index << " is " << value << "\n";
                }

                break;
            case 9:
                myList.print();
                break;
            case 10:
                std::cout << "Size of the list is " << myList.get_size() << "\n";
                break;
            case 11:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    }
    return 0;
}