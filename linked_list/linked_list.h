#pragma once
#include <stdexcept>
#include <iostream>

// 단일 연결 리스트 (Singly Linked List)
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    // 맨 앞에 삽입
    void push_front(const T& val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    // 맨 뒤에 삽입
    void push_back(const T& val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        size++;
    }

    // 특정 인덱스에 삽입
    void insert(int index, const T& val) {
        if (index < 0 || index > size)
            throw std::out_of_range("Index out of range");
        if (index == 0) {
            push_front(val);
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        size++;
    }

    // 맨 앞 제거
    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        Node* tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }

    // 맨 뒤 제거
    void pop_back() {
        if (!head) throw std::underflow_error("List is empty");
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* cur = head;
            while (cur->next->next) cur = cur->next;
            delete cur->next;
            cur->next = nullptr;
        }
        size--;
    }

    // 특정 값 제거 (첫 번째 발견)
    bool remove(const T& val) {
        if (!head) return false;
        if (head->data == val) {
            pop_front();
            return true;
        }
        Node* cur = head;
        while (cur->next) {
            if (cur->next->data == val) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                size--;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // 인덱스로 접근
    T& at(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->data;
    }

    // 값 검색 (인덱스 반환, 없으면 -1)
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
        size = 0;
    }

    void print() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << " -> NULL\n";
    }
};
