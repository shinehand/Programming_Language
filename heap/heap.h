#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

// 최대 힙 (Max Heap)
// 부모 노드가 자식 노드보다 항상 크거나 같음
template <typename T>
class MaxHeap {
private:
    std::vector<T> data;  // 1-based 인덱스 사용

    // 인덱스 계산
    int parent(int i) const { return i / 2; }
    int left(int i) const { return 2 * i; }
    int right(int i) const { return 2 * i + 1; }

    // 위로 올리기 (삽입 후 힙 속성 복구)
    void sift_up(int i) {
        while (i > 1 && data[parent(i)] < data[i]) {
            std::swap(data[parent(i)], data[i]);
            i = parent(i);
        }
    }

    // 아래로 내리기 (삭제 후 힙 속성 복구)
    void sift_down(int i) {
        int n = data.size() - 1;
        while (true) {
            int largest = i;
            int l = left(i), r = right(i);
            if (l <= n && data[l] > data[largest]) largest = l;
            if (r <= n && data[r] > data[largest]) largest = r;
            if (largest == i) break;
            std::swap(data[i], data[largest]);
            i = largest;
        }
    }

public:
    MaxHeap() {
        data.push_back(T{});  // 인덱스 0은 더미로 사용 (1-based)
    }

    // 원소 삽입 O(log n)
    void push(const T& val) {
        data.push_back(val);
        sift_up(data.size() - 1);
    }

    // 최댓값 제거 및 반환 O(log n)
    T pop() {
        if (empty()) throw std::underflow_error("Heap is empty");
        T max_val = data[1];
        data[1] = data.back();
        data.pop_back();
        if (!empty()) sift_down(1);
        return max_val;
    }

    // 최댓값 조회 O(1)
    const T& top() const {
        if (empty()) throw std::underflow_error("Heap is empty");
        return data[1];
    }

    bool empty() const { return data.size() == 1; }
    int size() const { return data.size() - 1; }

    void print() const {
        std::cout << "[";
        for (int i = 1; i < (int)data.size(); i++) {
            std::cout << data[i];
            if (i < (int)data.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
};

// 최소 힙 (Min Heap)
// 부모 노드가 자식 노드보다 항상 작거나 같음
template <typename T>
class MinHeap {
private:
    std::vector<T> data;

    int parent(int i) const { return i / 2; }
    int left(int i) const { return 2 * i; }
    int right(int i) const { return 2 * i + 1; }

    void sift_up(int i) {
        while (i > 1 && data[parent(i)] > data[i]) {
            std::swap(data[parent(i)], data[i]);
            i = parent(i);
        }
    }

    void sift_down(int i) {
        int n = data.size() - 1;
        while (true) {
            int smallest = i;
            int l = left(i), r = right(i);
            if (l <= n && data[l] < data[smallest]) smallest = l;
            if (r <= n && data[r] < data[smallest]) smallest = r;
            if (smallest == i) break;
            std::swap(data[i], data[smallest]);
            i = smallest;
        }
    }

public:
    MinHeap() {
        data.push_back(T{});
    }

    void push(const T& val) {
        data.push_back(val);
        sift_up(data.size() - 1);
    }

    T pop() {
        if (empty()) throw std::underflow_error("Heap is empty");
        T min_val = data[1];
        data[1] = data.back();
        data.pop_back();
        if (!empty()) sift_down(1);
        return min_val;
    }

    const T& top() const {
        if (empty()) throw std::underflow_error("Heap is empty");
        return data[1];
    }

    bool empty() const { return data.size() == 1; }
    int size() const { return data.size() - 1; }

    void print() const {
        std::cout << "[";
        for (int i = 1; i < (int)data.size(); i++) {
            std::cout << data[i];
            if (i < (int)data.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
};
