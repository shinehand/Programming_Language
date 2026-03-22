#include <iostream>
#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList<int> list;

    // 삽입 테스트
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(2, 99);  // 인덱스 2에 99 삽입

    std::cout << "앞에서부터: ";
    list.print_forward();   // 0 <-> 1 <-> 99 <-> 2 <-> 3 -> NULL

    std::cout << "뒤에서부터: ";
    list.print_backward();  // 3 <-> 2 <-> 99 <-> 1 <-> 0 -> NULL

    std::cout << "크기: " << list.get_size() << "\n";  // 5
    std::cout << "at(2): " << list.at(2) << "\n";       // 99
    std::cout << "find(99): " << list.find(99) << "\n"; // 2

    // 삭제 테스트
    list.remove(99);
    std::cout << "remove(99) 후: ";
    list.print_forward();  // 0 <-> 1 <-> 2 <-> 3 -> NULL

    list.pop_front();
    list.pop_back();
    std::cout << "pop_front/pop_back 후: ";
    list.print_forward();  // 1 <-> 2 -> NULL

    return 0;
}
