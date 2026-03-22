#include <iostream>
#include "queue.h"

int main() {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Queue: ";
    q.print();                          // [front] 1 | 2 | 3 [back]
    std::cout << "Front: " << q.front() << "\n";  // 1
    std::cout << "Back: " << q.back() << "\n";    // 3
    std::cout << "Size: " << q.size() << "\n";    // 3

    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 2

    std::cout << "Queue after dequeues: ";
    q.print();                          // [front] 3 [back]

    return 0;
}
