#include <iostream>
#include "circular_queue.h"

int main() {
    // 용량 6의 원형 큐 생성
    CircularQueue<int> cq(6);

    // 삽입
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    std::cout << "5개 삽입 후:\n";
    cq.print();

    // 일부 제거
    std::cout << "dequeue: " << cq.dequeue() << "\n";  // 1
    std::cout << "dequeue: " << cq.dequeue() << "\n";  // 2

    std::cout << "2개 제거 후:\n";
    cq.print();

    // 원형 특성 확인: 앞에서 제거한 자리에 다시 삽입
    cq.enqueue(6);
    cq.enqueue(7);

    std::cout << "2개 추가 삽입 후 (원형 특성):\n";
    cq.print();

    std::cout << "front: " << cq.front() << "\n";  // 3
    std::cout << "back: " << cq.back() << "\n";    // 7
    std::cout << "size: " << cq.size() << "\n";    // 5
    std::cout << "full: " << cq.full() << "\n";    // 0

    // 꽉 채우기
    cq.enqueue(8);
    std::cout << "\n6개 꽉 채운 후:\n";
    cq.print();
    std::cout << "full: " << cq.full() << "\n";  // 1

    // 모두 제거
    std::cout << "\n전체 dequeue: ";
    while (!cq.empty()) {
        std::cout << cq.dequeue() << " ";  // 3 4 5 6 7 8
    }
    std::cout << "\n";

    return 0;
}
