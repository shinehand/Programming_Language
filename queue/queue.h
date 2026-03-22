#pragma once
#include <stdexcept>
#include <iostream>

// 원형 배열 기반 큐 (Circular Array Queue)
template <typename T>
class Queue {
private:
    T* data;
    int head_idx;
    int tail_idx;
    int count;
    int capacity;

    void resize() {
        int new_cap = capacity * 2;
        T* new_data = new T[new_cap];
        for (int i = 0; i < count; i++) {
            new_data[i] = data[(head_idx + i) % capacity];
        }
        delete[] data;
        data = new_data;
        head_idx = 0;
        tail_idx = count;
        capacity = new_cap;
    }

public:
    Queue(int initial_capacity = 16)
        : head_idx(0), tail_idx(0), count(0), capacity(initial_capacity) {
        data = new T[capacity];
    }

    ~Queue() { delete[] data; }

    // 원소 삽입 (rear)
    void enqueue(const T& val) {
        if (count == capacity) resize();
        data[tail_idx] = val;
        tail_idx = (tail_idx + 1) % capacity;
        count++;
    }

    // 원소 제거 및 반환 (front)
    T dequeue() {
        if (empty()) throw std::underflow_error("Queue is empty");
        T val = data[head_idx];
        head_idx = (head_idx + 1) % capacity;
        count--;
        return val;
    }

    // 맨 앞 원소 조회
    T& front() {
        if (empty()) throw std::underflow_error("Queue is empty");
        return data[head_idx];
    }

    // 맨 뒤 원소 조회
    T& back() {
        if (empty()) throw std::underflow_error("Queue is empty");
        return data[(tail_idx - 1 + capacity) % capacity];
    }

    bool empty() const { return count == 0; }
    int size() const { return count; }

    void print() const {
        std::cout << "[front] ";
        for (int i = 0; i < count; i++) {
            std::cout << data[(head_idx + i) % capacity];
            if (i < count - 1) std::cout << " | ";
        }
        std::cout << " [back]\n";
    }
};
