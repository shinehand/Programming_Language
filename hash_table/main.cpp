#include <iostream>
#include <unordered_map>  // STL 해시 맵 예시
#include "hash_table.h"

int main() {
    // --- 체이닝 방식 해시 테이블 ---
    std::cout << "=== 체이닝 방식 해시 테이블 ===\n";
    HashTableChaining<std::string, int> ht1;

    ht1.insert("apple", 1);
    ht1.insert("banana", 2);
    ht1.insert("cherry", 3);
    ht1.insert("apple", 99);  // 기존 키 업데이트

    std::cout << "apple: " << ht1.get("apple") << "\n";    // 99
    std::cout << "banana: " << ht1.get("banana") << "\n";  // 2
    std::cout << "contains cherry: " << ht1.contains("cherry") << "\n";  // 1

    ht1.remove("banana");
    std::cout << "remove(banana) 후 contains: " << ht1.contains("banana") << "\n";  // 0
    std::cout << "크기: " << ht1.size() << "\n";  // 2

    std::cout << "\n해시 테이블 내부:\n";
    ht1.print();

    // --- 오픈 어드레싱 방식 ---
    std::cout << "\n=== 오픈 어드레싱 방식 해시 테이블 ===\n";
    HashTableOpenAddressing<std::string, int> ht2;

    ht2.insert("dog", 10);
    ht2.insert("cat", 20);
    ht2.insert("bird", 30);

    std::cout << "dog: " << ht2.get("dog") << "\n";   // 10
    std::cout << "cat: " << ht2.get("cat") << "\n";   // 20
    std::cout << "내부 상태:\n";
    ht2.print();

    ht2.remove("cat");
    std::cout << "remove(cat) 후:\n";
    ht2.print();

    // --- STL unordered_map 비교 ---
    std::cout << "\n=== STL unordered_map ===\n";
    std::unordered_map<std::string, int> stl_map;
    stl_map["one"] = 1;
    stl_map["two"] = 2;
    stl_map["three"] = 3;

    for (const auto& [key, val] : stl_map) {
        std::cout << key << ": " << val << "\n";
    }

    return 0;
}
