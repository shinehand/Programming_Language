#pragma once
#include <stdexcept>
#include <iostream>

// 이중 연결 리스트 (Doubly Linked List)
// 각 노드가 이전 노드와 다음 노드 양쪽을 가리킴
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;  // 첫 번째 노드
    Node* tail;  // 마지막 노드
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() { clear(); }

    // 맨 앞에 삽입 O(1)
    void push_front(const T& val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    // 맨 뒤에 삽입 O(1)
    void push_back(const T& val) {
        Node* node = new Node(val);
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    // 특정 인덱스에 삽입 O(n)
    void insert(int index, const T& val) {
        if (index < 0 || index > size)
            throw std::out_of_range("Index out of range");
        if (index == 0) { push_front(val); return; }
        if (index == size) { push_back(val); return; }

        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;

        Node* node = new Node(val);
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        size++;
    }

    // 맨 앞 제거 O(1)
    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        size--;
    }

    // 맨 뒤 제거 O(1)
    void pop_back() {
        if (!tail) throw std::underflow_error("List is empty");
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        size--;
    }

    // 특정 값 제거 (첫 번째 발견) O(n)
    bool remove(const T& val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == val) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;
                delete cur;
                size--;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // 인덱스로 접근 O(n)
    T& at(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->data;
    }

    // 값 검색 (인덱스 반환, 없으면 -1) O(n)
    int find(const T& val) const {
        Node* cur = head;
        int idx = 0;
        while (cur) {
            if (cur->data == val) return idx;
            cur = cur->next;
            idx++;
        }
        return -1;
    }

    int get_size() const { return size; }
    bool empty() const { return size == 0; }

    void clear() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        size = 0;
    }

    // 앞에서부터 출력
    void print_forward() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " <-> ";
            cur = cur->next;
        }
        std::cout << " -> NULL\n";
    }

    // 뒤에서부터 출력
    void print_backward() const {
        Node* cur = tail;
        while (cur) {
            std::cout << cur->data;
            if (cur->prev) std::cout << " <-> ";
            cur = cur->prev;
        }
        std::cout << " -> NULL\n";
    }
};
