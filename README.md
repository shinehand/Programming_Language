# C++ 기본 자료구조 모음

C++로 구현한 기본 자료구조 모음입니다. 각 자료구조는 템플릿(`template<typename T>`)으로 작성되어 다양한 타입에 활용할 수 있습니다.

---

## 목차

- [연결 리스트 (Linked List)](#연결-리스트-linked-list)
- [스택 (Stack)](#스택-stack)
- [큐 (Queue)](#큐-queue)
- [쿼드트리 (Quad Tree)](#쿼드트리-quad-tree)

---

## 연결 리스트 (Linked List)

**경로:** `linked_list/`

단방향 연결 리스트(Singly Linked List)입니다. 각 노드는 데이터와 다음 노드를 가리키는 포인터를 가집니다.

### 구조

```
head → [1] → [2] → [3] → NULL
```

### 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `push_front(val)` | 맨 앞에 삽입 | O(1) |
| `push_back(val)` | 맨 뒤에 삽입 | O(n) |
| `insert(idx, val)` | 특정 인덱스에 삽입 | O(n) |
| `pop_front()` | 맨 앞 제거 | O(1) |
| `pop_back()` | 맨 뒤 제거 | O(n) |
| `remove(val)` | 특정 값 제거 (첫 번째) | O(n) |
| `at(idx)` | 인덱스로 원소 접근 | O(n) |
| `find(val)` | 값 검색 (인덱스 반환) | O(n) |

### 사용 예시

```cpp
LinkedList<int> list;

list.push_back(1);
list.push_back(2);
list.push_back(3);
list.push_front(0);
list.insert(2, 99);

list.print();  // 0 -> 1 -> 99 -> 2 -> 3 -> NULL

list.remove(99);
list.at(1);    // 1
list.find(2);  // 2 (인덱스)
```

### 컴파일 및 실행

```bash
g++ -std=c++17 linked_list/main.cpp -o ll && ./ll
```

---

## 스택 (Stack)

**경로:** `stack/`

배열 기반 스택입니다. LIFO(Last In, First Out) 구조로, 용량이 가득 차면 자동으로 2배 확장됩니다.

### 구조

```
push →  [top] 3 | 2 | 1 [bottom]  → pop
```

### 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `push(val)` | 원소 추가 | O(1) 분할 상환 |
| `pop()` | 최상단 원소 제거 및 반환 | O(1) |
| `top()` | 최상단 원소 조회 | O(1) |
| `empty()` | 비어 있는지 확인 | O(1) |
| `size()` | 원소 개수 반환 | O(1) |

### 사용 예시

```cpp
Stack<int> s;

s.push(1);
s.push(2);
s.push(3);

s.top();   // 3
s.pop();   // 3 반환 후 제거
s.size();  // 2
```

### 컴파일 및 실행

```bash
g++ -std=c++17 stack/main.cpp -o stack && ./stack
```

---

## 큐 (Queue)

**경로:** `queue/`

원형 배열(Circular Array) 기반 큐입니다. FIFO(First In, First Out) 구조로, 용량이 가득 차면 자동으로 2배 확장됩니다.

### 구조

```
enqueue →  [front] 1 | 2 | 3 [back]  → dequeue
```

### 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `enqueue(val)` | 원소 삽입 (rear) | O(1) 분할 상환 |
| `dequeue()` | 원소 제거 및 반환 (front) | O(1) |
| `front()` | 맨 앞 원소 조회 | O(1) |
| `back()` | 맨 뒤 원소 조회 | O(1) |
| `empty()` | 비어 있는지 확인 | O(1) |
| `size()` | 원소 개수 반환 | O(1) |

### 사용 예시

```cpp
Queue<int> q;

q.enqueue(1);
q.enqueue(2);
q.enqueue(3);

q.front();    // 1
q.back();     // 3
q.dequeue();  // 1 반환 후 제거
q.size();     // 2
```

### 컴파일 및 실행

```bash
g++ -std=c++17 queue/main.cpp -o queue && ./queue
```

---

## 쿼드트리 (Quad Tree)

**경로:** `quad_tree/`

2D 공간 분할에 사용되는 쿼드트리입니다. 하나의 노드에 최대 4개의 점을 저장하고, 초과 시 공간을 4개의 사분면(NW, NE, SW, SE)으로 분할합니다. 게임, 지도, 충돌 감지 등에 활용됩니다.

### 구조

```
┌─────────┬─────────┐
│  NW     │  NE     │
│  (•)    │  (•)(•) │
├─────────┼─────────┤
│  SW     │  SE     │
│ (•)(•)  │  (•)    │
└─────────┴─────────┘
```

### 주요 클래스 및 구조체

| 이름 | 설명 |
|---|---|
| `Point` | 2D 좌표 (x, y) |
| `AABB` | 축 정렬 경계 박스 (중심 좌표 + 반너비/반높이) |
| `QuadTree` | 쿼드트리 본체 |

### 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `insert(point)` | 점 삽입 | O(log n) 평균 |
| `query(aabb, result)` | 범위 내 점 검색 | O(log n + k) |
| `count()` | 총 점 개수 반환 | O(n) |
| `print()` | 트리 구조 출력 | O(n) |

### 사용 예시

```cpp
// 100x100 공간의 쿼드트리 생성 (중심: 50, 50)
QuadTree qt(AABB(50, 50, 50, 50));

qt.insert(Point(10, 10));
qt.insert(Point(75, 30));
qt.insert(Point(20, 80));

// (0~30, 0~60) 범위 내 점 검색
AABB range(15, 30, 15, 30);
std::vector<Point> found;
qt.query(range, found);
// found = { (10, 10), (15, 45) ... }
```

### 컴파일 및 실행

```bash
g++ -std=c++17 quad_tree/main.cpp -o quad_tree && ./quad_tree
```

---

## 디렉터리 구조

```
Programming_Language/
├── linked_list/
│   ├── linked_list.h   # 연결 리스트 구현
│   └── main.cpp        # 사용 예시
├── stack/
│   ├── stack.h         # 스택 구현
│   └── main.cpp        # 사용 예시
├── queue/
│   ├── queue.h         # 큐 구현
│   └── main.cpp        # 사용 예시
└── quad_tree/
    ├── quad_tree.h     # 쿼드트리 구현
    └── main.cpp        # 사용 예시
```

## 요구 사항

- C++17 이상
- g++ 또는 clang++
