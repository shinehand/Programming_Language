#include <iostream>
#include <queue>  // std::priority_queue 예시용
#include "heap.h"

int main() {
    // --- 최대 힙 ---
    std::cout << "=== 최대 힙 (Max Heap) ===\n";
    MaxHeap<int> maxHeap;

    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(9);
    maxHeap.push(2);
    maxHeap.push(6);

    std::cout << "삽입 후: ";
    maxHeap.print();  // 최대 힙 배열 형태

    std::cout << "최댓값: " << maxHeap.top() << "\n";  // 9

    std::cout << "pop 순서: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.pop() << " ";  // 9 6 5 4 3 2 1 1
    }
    std::cout << "\n\n";

    // --- 최소 힙 ---
    std::cout << "=== 최소 힙 (Min Heap) ===\n";
    MinHeap<int> minHeap;

    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(9);
    minHeap.push(2);
    minHeap.push(6);

    std::cout << "삽입 후: ";
    minHeap.print();

    std::cout << "최솟값: " << minHeap.top() << "\n";  // 1

    std::cout << "pop 순서: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.pop() << " ";  // 1 1 2 3 4 5 6 9
    }
    std::cout << "\n\n";

    // --- std::priority_queue 사용 예시 ---
    std::cout << "=== std::priority_queue (STL 최대 힙) ===\n";
    std::priority_queue<int> pq;
    pq.push(3); pq.push(1); pq.push(4); pq.push(1); pq.push(5);

    std::cout << "pop 순서: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}
