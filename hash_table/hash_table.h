#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <functional>

// 해시 테이블 - 체이닝 방식 (Separate Chaining)
// 충돌 발생 시 연결 리스트로 처리
template <typename K, typename V>
class HashTableChaining {
private:
    static const int DEFAULT_SIZE = 16;
    std::vector<std::list<std::pair<K, V>>> table;
    int capacity;
    int count;

    // 해시 함수
    int hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

public:
    HashTableChaining(int cap = DEFAULT_SIZE)
        : capacity(cap), count(0), table(cap) {}

    // 삽입 / 수정 O(1) 평균
    void insert(const K& key, const V& val) {
        int idx = hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = val;  // 기존 키면 값 업데이트
                return;
            }
        }
        table[idx].emplace_back(key, val);
        count++;
    }

    // 탐색 O(1) 평균
    V& get(const K& key) {
        int idx = hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) return pair.second;
        }
        throw std::out_of_range("Key not found");
    }

    // 삭제 O(1) 평균
    bool remove(const K& key) {
        int idx = hash(key);
        auto& chain = table[idx];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                count--;
                return true;
            }
        }
        return false;
    }

    // 키 존재 여부 확인
    bool contains(const K& key) const {
        int idx = hash(key);
        for (const auto& pair : table[idx]) {
            if (pair.first == key) return true;
        }
        return false;
    }

    int size() const { return count; }
    bool empty() const { return count == 0; }

    void print() const {
        for (int i = 0; i < capacity; i++) {
            if (!table[i].empty()) {
                std::cout << "[" << i << "]: ";
                for (const auto& pair : table[i]) {
                    std::cout << "(" << pair.first << "," << pair.second << ") -> ";
                }
                std::cout << "NULL\n";
            }
        }
    }
};

// 해시 테이블 - 오픈 어드레싱 방식 (Open Addressing, Linear Probing)
// 충돌 발생 시 다음 빈 슬롯을 찾아 저장
template <typename K, typename V>
class HashTableOpenAddressing {
private:
    enum class State { EMPTY, OCCUPIED, DELETED };

    struct Slot {
        K key;
        V value;
        State state;
        Slot() : state(State::EMPTY) {}
    };

    std::vector<Slot> table;
    int capacity;
    int count;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

public:
    HashTableOpenAddressing(int cap = 16)
        : capacity(cap), count(0), table(cap) {}

    // 삽입 O(1) 평균
    void insert(const K& key, const V& val) {
        if (count >= capacity / 2) {
            throw std::overflow_error("Hash table is too full");
        }
        int idx = hash(key);
        while (table[idx].state == State::OCCUPIED) {
            if (table[idx].key == key) {
                table[idx].value = val;  // 업데이트
                return;
            }
            idx = (idx + 1) % capacity;  // 선형 탐사
        }
        table[idx].key = key;
        table[idx].value = val;
        table[idx].state = State::OCCUPIED;
        count++;
    }

    // 탐색 O(1) 평균
    V& get(const K& key) {
        int idx = hash(key);
        int start = idx;
        while (table[idx].state != State::EMPTY) {
            if (table[idx].state == State::OCCUPIED && table[idx].key == key) {
                return table[idx].value;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        throw std::out_of_range("Key not found");
    }

    // 삭제 O(1) 평균
    bool remove(const K& key) {
        int idx = hash(key);
        int start = idx;
        while (table[idx].state != State::EMPTY) {
            if (table[idx].state == State::OCCUPIED && table[idx].key == key) {
                table[idx].state = State::DELETED;  // 논리적 삭제
                count--;
                return true;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }

    bool contains(const K& key) const {
        int idx = hash(key);
        int start = idx;
        while (table[idx].state != State::EMPTY) {
            if (table[idx].state == State::OCCUPIED && table[idx].key == key) {
                return true;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }

    int size() const { return count; }

    void print() const {
        for (int i = 0; i < capacity; i++) {
            if (table[i].state == State::OCCUPIED) {
                std::cout << "[" << i << "]: (" << table[i].key << ", " << table[i].value << ")\n";
            } else if (table[i].state == State::DELETED) {
                std::cout << "[" << i << "]: DELETED\n";
            }
        }
    }
};
