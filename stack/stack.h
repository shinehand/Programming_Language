#pragma once
#include <stdexcept>
#include <iostream>

// 배열 기반 스택 (Array-based Stack)
template <typename T>
class Stack {
private:
    T* data;
    int top_idx;
    int capacity;

    void resize() {
        capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i <= top_idx; i++) new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }

public:
    Stack(int initial_capacity = 16)
        : top_idx(-1), capacity(initial_capacity) {
        data = new T[capacity];
    }

    ~Stack() { delete[] data; }

    // 원소 추가
    void push(const T& val) {
        if (top_idx + 1 == capacity) resize();
        data[++top_idx] = val;
    }

    // 원소 제거 및 반환
    T pop() {
        if (empty()) throw std::underflow_error("Stack is empty");
        return data[top_idx--];
    }

    // 최상단 원소 조회
    T& top() {
        if (empty()) throw std::underflow_error("Stack is empty");
        return data[top_idx];
    }

    const T& top() const {
        if (empty()) throw std::underflow_error("Stack is empty");
        return data[top_idx];
    }

    bool empty() const { return top_idx == -1; }
    int size() const { return top_idx + 1; }

    void print() const {
        std::cout << "[top] ";
        for (int i = top_idx; i >= 0; i--) {
            std::cout << data[i];
            if (i > 0) std::cout << " | ";
        }
        std::cout << " [bottom]\n";
    }
};
