# 힙 (Heap) / 우선순위 큐 (Priority Queue)

## 개념

힙(Heap)은 **완전 이진 트리**를 기반으로 하며, 부모-자식 간 우선순위 관계를 유지하는 자료구조입니다.

- **최대 힙 (Max Heap)**: 부모 노드 ≥ 자식 노드 → 루트가 항상 최댓값
- **최소 힙 (Min Heap)**: 부모 노드 ≤ 자식 노드 → 루트가 항상 최솟값

### 배열로 표현하는 힙 (1-based index)

```
인덱스:  1   2   3   4   5   6   7
값:     [9] [6] [5] [3] [1] [2] [4]

트리:
        9
       / \
      6   5
     / \ / \
    3  1 2  4
```

- `parent(i)` = `i / 2`
- `left(i)` = `2 * i`
- `right(i)` = `2 * i + 1`

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `push(val)` | 원소 삽입 | O(log n) |
| `pop()` | 최대/최소값 제거 및 반환 | O(log n) |
| `top()` | 최대/최소값 조회 | O(1) |
| `size()` | 원소 개수 | O(1) |
| `empty()` | 비어 있는지 확인 | O(1) |

## STL 우선순위 큐

```cpp
#include <queue>

// 최대 힙 (기본)
std::priority_queue<int> maxPQ;

// 최소 힙
std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
```

## 활용 분야

- 다익스트라 최단 경로 알고리즘
- 힙 정렬 (Heap Sort)
- 작업 스케줄링 (우선순위 기반)

## 컴파일 및 실행

```bash
g++ -std=c++17 heap/main.cpp -o heap && ./heap
```
