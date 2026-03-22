#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>

// STL 기초 (Standard Template Library)
// C++ 표준 라이브러리의 자료구조와 알고리즘 모음

void demonstrate_vector() {
    std::cout << "=== vector ===\n";
    // 동적 배열 - 가장 많이 사용하는 컨테이너

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    v.push_back(5);   // 뒤에 추가
    v.pop_back();     // 뒤에서 제거
    v.insert(v.begin() + 2, 99);  // 인덱스 2에 삽입
    v.erase(v.begin() + 2);       // 인덱스 2 삭제

    std::cout << "원소: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "크기: " << v.size() << ", 용량: " << v.capacity() << "\n";
    std::cout << "v[0]: " << v[0] << ", v.at(1): " << v.at(1) << "\n";
    std::cout << "front: " << v.front() << ", back: " << v.back() << "\n";

    // 정렬
    std::sort(v.begin(), v.end());
    std::cout << "정렬 후: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // 탐색
    auto it = std::find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        std::cout << "5 발견, 인덱스: " << (it - v.begin()) << "\n";
    }
}

void demonstrate_map() {
    std::cout << "\n=== map (정렬된 키-값 쌍) ===\n";
    // 레드-블랙 트리 기반, 키 정렬 O(log n)

    std::map<std::string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;
    scores.insert({"Dave", 78});

    // 순회 (키 순서로 정렬되어 출력)
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << "\n";
    }

    // 탐색
    auto it = scores.find("Bob");
    if (it != scores.end()) {
        std::cout << "Bob의 점수: " << it->second << "\n";
    }

    // 수정 및 삭제
    scores["Bob"] = 90;
    scores.erase("Charlie");
    std::cout << "Bob 수정, Charlie 삭제 후 크기: " << scores.size() << "\n";

    // count로 키 존재 여부 확인
    std::cout << "Alice 존재: " << scores.count("Alice") << "\n";
}

void demonstrate_set() {
    std::cout << "\n=== set (중복 없는 집합) ===\n";
    // 레드-블랙 트리 기반, 중복 없이 정렬 저장

    std::set<int> s = {5, 3, 8, 1, 9, 3, 5};  // 중복 자동 제거

    std::cout << "원소 (중복 제거, 정렬): ";
    for (int x : s) std::cout << x << " ";  // 1 3 5 8 9
    std::cout << "\n";

    s.insert(7);
    s.erase(3);

    std::cout << "7 삽입, 3 삭제 후: ";
    for (int x : s) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "5 존재 여부: " << s.count(5) << "\n";

    // lower_bound, upper_bound
    auto lb = s.lower_bound(6);
    std::cout << "lower_bound(6): " << *lb << "\n";  // 7
}

void demonstrate_unordered_map() {
    std::cout << "\n=== unordered_map (해시 맵) ===\n";
    // 해시 테이블 기반, 평균 O(1) 연산

    std::unordered_map<std::string, int> freq;

    // 단어 빈도 계산
    std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    for (const auto& w : words) {
        freq[w]++;  // 없으면 0으로 초기화 후 증가
    }

    for (const auto& [word, count] : freq) {
        std::cout << word << ": " << count << "번\n";
    }
}

void demonstrate_algorithms() {
    std::cout << "\n=== STL 알고리즘 ===\n";

    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 정렬
    std::sort(v.begin(), v.end());
    std::cout << "sort: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // 역순 정렬
    std::sort(v.begin(), v.end(), std::greater<int>());
    std::cout << "역순 sort: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // 최대/최소
    std::cout << "max: " << *std::max_element(v.begin(), v.end()) << "\n";
    std::cout << "min: " << *std::min_element(v.begin(), v.end()) << "\n";

    // 합계
    std::cout << "sum: " << std::accumulate(v.begin(), v.end(), 0) << "\n";

    // 개수 세기
    std::cout << "5 이상인 개수: " << std::count_if(v.begin(), v.end(),
                                   [](int x) { return x >= 5; }) << "\n";

    // 변환
    std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
    std::cout << "모두 2배: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    demonstrate_vector();
    demonstrate_map();
    demonstrate_set();
    demonstrate_unordered_map();
    demonstrate_algorithms();

    return 0;
}
