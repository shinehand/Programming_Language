#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Stack: ";
    s.print();                       // [top] 3 | 2 | 1 [bottom]
    std::cout << "Top: " << s.top() << "\n";  // 3
    std::cout << "Size: " << s.size() << "\n"; // 3

    std::cout << "Pop: " << s.pop() << "\n";  // 3
    std::cout << "Pop: " << s.pop() << "\n";  // 2

    std::cout << "Stack after pops: ";
    s.print();                       // [top] 1 [bottom]

    return 0;
}
