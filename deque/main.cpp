#include <iostream>
#include <deque>  // STL deque 예시
#include "deque.h"

int main() {
    std::cout << "=== 커스텀 Deque ===\n";
    Deque<int> dq;

    // 삽입
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_front(2);
    dq.push_front(1);

    std::cout << "삽입 후: ";
    dq.print();  // [front] 1 | 2 | 3 | 4 | 5 [back]

    std::cout << "front: " << dq.front() << "\n";  // 1
    std::cout << "back: " << dq.back() << "\n";    // 5
    std::cout << "size: " << dq.size() << "\n";    // 5

    // 제거
    std::cout << "pop_front: " << dq.pop_front() << "\n";  // 1
    std::cout << "pop_back: " << dq.pop_back() << "\n";    // 5
    std::cout << "제거 후: ";
    dq.print();  // [front] 2 | 3 | 4 [back]

    // --- STL deque 비교 ---
    std::cout << "\n=== STL std::deque ===\n";
    std::deque<int> sdq;

    sdq.push_back(3);
    sdq.push_front(2);
    sdq.push_front(1);
    sdq.push_back(4);

    std::cout << "front: " << sdq.front() << "\n";  // 1
    std::cout << "back: " << sdq.back() << "\n";    // 4

    sdq.pop_front();
    sdq.pop_back();

    for (int x : sdq) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
