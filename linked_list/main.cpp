#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(2, 99);

    std::cout << "List: ";
    list.print();                          // 0 -> 1 -> 99 -> 2 -> 3 -> NULL

    std::cout << "Size: " << list.get_size() << "\n";  // 5
    std::cout << "at(2): " << list.at(2) << "\n";      // 99
    std::cout << "find(99): " << list.find(99) << "\n"; // 2

    list.remove(99);
    std::cout << "After remove(99): ";
    list.print();                          // 0 -> 1 -> 2 -> 3 -> NULL

    list.pop_front();
    list.pop_back();
    std::cout << "After pop_front/pop_back: ";
    list.print();                          // 1 -> 2 -> NULL

    return 0;
}
