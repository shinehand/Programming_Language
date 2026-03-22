# 이중 연결 리스트 (Doubly Linked List)

## 개념

이중 연결 리스트는 각 노드가 **이전 노드(prev)**와 **다음 노드(next)** 양쪽 방향의 포인터를 가지는 자료구조입니다.

### 구조

```
NULL ← [0] ⇄ [1] ⇄ [2] ⇄ [3] → NULL
       ↑                    ↑
      head                 tail
```

## 단일 연결 리스트와의 비교

| 특징 | 단일 연결 리스트 | 이중 연결 리스트 |
|---|---|---|
| 메모리 | 포인터 1개/노드 | 포인터 2개/노드 |
| 역방향 탐색 | ❌ | ✅ |
| 삭제 (노드 포인터 사용 시) | O(n) | O(1) |
| `pop_back` | O(n) | O(1) |

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `push_front(val)` | 맨 앞에 삽입 | O(1) |
| `push_back(val)` | 맨 뒤에 삽입 | O(1) |
| `insert(idx, val)` | 특정 인덱스에 삽입 | O(n) |
| `pop_front()` | 맨 앞 제거 | O(1) |
| `pop_back()` | 맨 뒤 제거 | O(1) |
| `remove(val)` | 특정 값 제거 | O(n) |
| `at(idx)` | 인덱스로 접근 | O(n) |
| `find(val)` | 값 검색 | O(n) |
| `print_forward()` | 앞에서부터 출력 | O(n) |
| `print_backward()` | 뒤에서부터 출력 | O(n) |

## 사용 예시

```cpp
DoublyLinkedList<int> list;
list.push_back(1);
list.push_back(2);
list.push_front(0);

list.print_forward();   // 0 <-> 1 <-> 2 -> NULL
list.print_backward();  // 2 <-> 1 <-> 0 -> NULL
```

## 컴파일 및 실행

```bash
g++ -std=c++17 doubly_linked_list/main.cpp -o dll && ./dll
```
