#pragma once
#include <stdexcept>
#include <iostream>

// 원형 큐 (Circular Queue) - 배열 기반
// 배열의 끝에 도달하면 다시 처음으로 돌아가는 구조
// FIFO(First In, First Out) 자료구조
template <typename T>
class CircularQueue {
private:
    T* data;
    int front_idx;  // 앞 포인터
    int back_idx;   // 뒤 포인터
    int count;      // 원소 개수
    int capacity;   // 전체 용량

public:
    explicit CircularQueue(int cap = 8)
        : capacity(cap), count(0), front_idx(0), back_idx(0) {
        data = new T[capacity];
    }

    ~CircularQueue() { delete[] data; }

    // 삽입 O(1)
    void enqueue(const T& val) {
        if (full()) throw std::overflow_error("Queue is full");
        data[back_idx] = val;
        back_idx = (back_idx + 1) % capacity;  // 원형으로 이동
        count++;
    }

    // 제거 및 반환 O(1)
    T dequeue() {
        if (empty()) throw std::underflow_error("Queue is empty");
        T val = data[front_idx];
        front_idx = (front_idx + 1) % capacity;  // 원형으로 이동
        count--;
        return val;
    }

    // 앞 원소 조회 O(1)
    const T& front() const {
        if (empty()) throw std::underflow_error("Queue is empty");
        return data[front_idx];
    }

    // 뒤 원소 조회 O(1)
    const T& back() const {
        if (empty()) throw std::underflow_error("Queue is empty");
        return data[(back_idx - 1 + capacity) % capacity];
    }

    bool empty() const { return count == 0; }
    bool full() const { return count == capacity; }
    int size() const { return count; }

    void print() const {
        std::cout << "[front] ";
        for (int i = 0; i < count; i++) {
            std::cout << data[(front_idx + i) % capacity];
            if (i < count - 1) std::cout << " | ";
        }
        std::cout << " [back]\n";
        std::cout << "  (front_idx=" << front_idx << ", back_idx=" << back_idx
                  << ", count=" << count << "/" << capacity << ")\n";
    }
};
