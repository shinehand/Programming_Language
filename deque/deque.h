#pragma once
#include <stdexcept>
#include <iostream>

// 양방향 큐 (Double-Ended Queue, Deque)
// 앞과 뒤 양쪽에서 삽입/삭제가 가능한 자료구조
// 이중 연결 리스트를 이용한 구현
template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;  // 앞(front)
    Node* tail;  // 뒤(back)
    int count;

public:
    Deque() : head(nullptr), tail(nullptr), count(0) {}

    ~Deque() { clear(); }

    // 앞에 삽입 O(1)
    void push_front(const T& val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        count++;
    }

    // 뒤에 삽입 O(1)
    void push_back(const T& val) {
        Node* node = new Node(val);
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        count++;
    }

    // 앞에서 제거 및 반환 O(1)
    T pop_front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        T val = head->data;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        count--;
        return val;
    }

    // 뒤에서 제거 및 반환 O(1)
    T pop_back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        T val = tail->data;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        count--;
        return val;
    }

    // 앞 원소 조회 O(1)
    const T& front() const {
        if (empty()) throw std::underflow_error("Deque is empty");
        return head->data;
    }

    // 뒤 원소 조회 O(1)
    const T& back() const {
        if (empty()) throw std::underflow_error("Deque is empty");
        return tail->data;
    }

    bool empty() const { return count == 0; }
    int size() const { return count; }

    void clear() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        count = 0;
    }

    void print() const {
        Node* cur = head;
        std::cout << "[front] ";
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " | ";
            cur = cur->next;
        }
        std::cout << " [back]\n";
    }
};
