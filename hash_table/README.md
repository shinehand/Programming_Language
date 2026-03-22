# 해시 테이블 (Hash Table)

## 개념

해시 테이블은 **해시 함수**를 사용해 키(key)를 배열 인덱스로 변환하여 값(value)을 저장하는 자료구조입니다. 평균 O(1)의 매우 빠른 탐색/삽입/삭제를 제공합니다.

### 구조

```
key → hash(key) → index → value
"apple" → hash → 3 → 1
```

## 충돌 해결 방법

### 1. 체이닝 (Separate Chaining)
각 슬롯에 연결 리스트를 유지하여 충돌된 항목을 같은 슬롯에 연결

```
[0]: NULL
[1]: (apple,1) → (banana,2) → NULL
[2]: (cherry,3) → NULL
```

### 2. 오픈 어드레싱 (Open Addressing - Linear Probing)
충돌 발생 시 다음 빈 슬롯을 찾아 저장

```
[0]: EMPTY
[1]: (apple, 1)
[2]: (banana, 2)  ← 충돌로 이동
```

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `insert(key, val)` | 삽입/수정 | O(1) 평균 |
| `get(key)` | 탐색 | O(1) 평균 |
| `remove(key)` | 삭제 | O(1) 평균 |
| `contains(key)` | 존재 여부 확인 | O(1) 평균 |

## STL 사용법

```cpp
#include <unordered_map>
std::unordered_map<std::string, int> map;
map["key"] = 1;
map.count("key");  // 존재 여부
map.erase("key");  // 삭제
```

## 컴파일 및 실행

```bash
g++ -std=c++17 hash_table/main.cpp -o hash_table && ./hash_table
```
