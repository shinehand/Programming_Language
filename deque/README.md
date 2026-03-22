# 양방향 큐 (Deque, Double-Ended Queue)

## 개념

덱(Deque)은 **앞(front)**과 **뒤(back)** 양쪽에서 삽입과 삭제가 모두 가능한 자료구조입니다. 스택과 큐를 일반화한 형태입니다.

### 구조

```
push_front →  [1] | [2] | [3] | [4] | [5]  ← push_back
pop_front  ←                               → pop_back
```

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `push_front(val)` | 앞에 삽입 | O(1) |
| `push_back(val)` | 뒤에 삽입 | O(1) |
| `pop_front()` | 앞에서 제거 및 반환 | O(1) |
| `pop_back()` | 뒤에서 제거 및 반환 | O(1) |
| `front()` | 앞 원소 조회 | O(1) |
| `back()` | 뒤 원소 조회 | O(1) |
| `size()` | 원소 개수 | O(1) |
| `empty()` | 비어 있는지 확인 | O(1) |

## STL 사용법

```cpp
#include <deque>
std::deque<int> dq;

dq.push_front(1);
dq.push_back(2);
dq.pop_front();  // 앞에서 제거
dq.pop_back();   // 뒤에서 제거
```

## 활용 분야

- BFS (너비 우선 탐색)
- 슬라이딩 윈도우 알고리즘
- 팰린드롬 확인
- 작업 스케줄링

## 컴파일 및 실행

```bash
g++ -std=c++17 deque/main.cpp -o deque && ./deque
```
