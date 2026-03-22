# STL 기초 (Standard Template Library)

## 주요 컨테이너

| 컨테이너 | 특징 | 내부 구조 |
|---|---|---|
| `vector` | 동적 배열, 임의 접근 O(1) | 배열 |
| `list` | 양방향 연결 리스트 | 연결 리스트 |
| `map` | 정렬된 키-값 쌍 | 레드-블랙 트리 |
| `set` | 중복 없는 정렬 집합 | 레드-블랙 트리 |
| `unordered_map` | 해시 맵, 평균 O(1) | 해시 테이블 |
| `unordered_set` | 해시 집합, 평균 O(1) | 해시 테이블 |

## 유용한 알고리즘

```cpp
#include <algorithm>
std::sort(v.begin(), v.end());           // 정렬
std::find(v.begin(), v.end(), val);      // 탐색
std::count_if(v.begin(), v.end(), pred); // 조건부 개수
std::transform(v.begin(), v.end(), ...); // 변환
```

## 컴파일 및 실행

```bash
g++ -std=c++17 stl_basics/stl_basics.cpp -o stl && ./stl
```
