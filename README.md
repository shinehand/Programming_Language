# C++ 기초 학습 모음

C++로 구현한 자료구조, 알고리즘, C++ 기초 문법 예제 모음입니다. 각 예제는 템플릿(`template<typename T>`)으로 작성되어 다양한 타입에 활용할 수 있으며, 한국어 주석으로 학습에 최적화되어 있습니다.

---

## 목차

### 📦 자료구조 (Data Structures)
- [연결 리스트 (Linked List)](#연결-리스트-linked-list)
- [이중 연결 리스트 (Doubly Linked List)](#이중-연결-리스트-doubly-linked-list)
- [스택 (Stack)](#스택-stack)
- [큐 (Queue)](#큐-queue)
- [원형 큐 (Circular Queue)](#원형-큐-circular-queue)
- [양방향 큐 (Deque)](#양방향-큐-deque)
- [이진 탐색 트리 (Binary Search Tree)](#이진-탐색-트리-binary-search-tree)
- [힙 (Heap)](#힙-heap)
- [해시 테이블 (Hash Table)](#해시-테이블-hash-table)
- [그래프 (Graph)](#그래프-graph)
- [트라이 (Trie)](#트라이-trie)
- [쿼드트리 (Quad Tree)](#쿼드트리-quad-tree)

### 🔍 알고리즘 (Algorithms)
- [정렬 (Sorting)](#정렬-sorting)
- [탐색 (Searching)](#탐색-searching)
- [BFS / DFS](#bfs--dfs)
- [재귀 (Recursion)](#재귀-recursion)
- [동적 프로그래밍 (Dynamic Programming)](#동적-프로그래밍-dynamic-programming)

### 📚 C++ 기초 문법
- [포인터 (Pointers)](#포인터-pointers)
- [스마트 포인터 (Smart Pointers)](#스마트-포인터-smart-pointers)
- [템플릿 (Templates)](#템플릿-templates)
- [객체지향 프로그래밍 (OOP)](#객체지향-프로그래밍-oop)
- [STL 기초 (STL Basics)](#stl-기초-stl-basics)
- [파일 입출력 (File I/O)](#파일-입출력-file-io)
- [예외 처리 (Exception Handling)](#예외-처리-exception-handling)
- [람다 표현식 (Lambda)](#람다-표현식-lambda)
- [이동 시맨틱 (Move Semantics)](#이동-시맨틱-move-semantics)

---

## 📦 자료구조 (Data Structures)

## 연결 리스트 (Linked List)

**경로:** `linked_list/`

단방향 연결 리스트(Singly Linked List)입니다.

```
head → [1] → [2] → [3] → NULL
```

### 컴파일 및 실행

```bash
g++ -std=c++17 linked_list/main.cpp -o ll && ./ll
```

---

## 이중 연결 리스트 (Doubly Linked List)

**경로:** `doubly_linked_list/`

각 노드가 이전/다음 양쪽 방향 포인터를 가지는 연결 리스트입니다. `pop_back`이 O(1)입니다.

```
NULL ← [0] ⇄ [1] ⇄ [2] ⇄ [3] → NULL
```

### 컴파일 및 실행

```bash
g++ -std=c++17 doubly_linked_list/main.cpp -o dll && ./dll
```

---

## 스택 (Stack)

**경로:** `stack/`

배열 기반 스택입니다. LIFO(Last In, First Out) 구조로, 용량이 가득 차면 자동으로 2배 확장됩니다.

```
push →  [top] 3 | 2 | 1 [bottom]  → pop
```

### 컴파일 및 실행

```bash
g++ -std=c++17 stack/main.cpp -o stack && ./stack
```

---

## 큐 (Queue)

**경로:** `queue/`

원형 배열(Circular Array) 기반 큐입니다. FIFO(First In, First Out) 구조입니다.

```
enqueue →  [front] 1 | 2 | 3 [back]  → dequeue
```

### 컴파일 및 실행

```bash
g++ -std=c++17 queue/main.cpp -o queue && ./queue
```

---

## 원형 큐 (Circular Queue)

**경로:** `circular_queue/`

배열 기반 원형 큐입니다. 나머지 연산으로 인덱스를 원형으로 관리합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 circular_queue/main.cpp -o cq && ./cq
```

---

## 양방향 큐 (Deque)

**경로:** `deque/`

앞과 뒤 양쪽에서 O(1) 삽입/삭제가 가능한 자료구조입니다.

```
push_front →  [1] | [2] | [3]  ← push_back
```

### 컴파일 및 실행

```bash
g++ -std=c++17 deque/main.cpp -o deque && ./deque
```

---

## 이진 탐색 트리 (Binary Search Tree)

**경로:** `binary_tree/`

왼쪽 < 루트 < 오른쪽 속성을 유지하는 이진 트리입니다. 삽입/탐색/삭제 및 4가지 순회를 지원합니다.

```
        5
       / \
      3   7
     / \ / \
    1  4 6  9
```

### 컴파일 및 실행

```bash
g++ -std=c++17 binary_tree/main.cpp -o bst && ./bst
```

---

## 힙 (Heap)

**경로:** `heap/`

최대 힙/최소 힙 구현과 STL `priority_queue` 사용 예시를 포함합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 heap/main.cpp -o heap && ./heap
```

---

## 해시 테이블 (Hash Table)

**경로:** `hash_table/`

체이닝과 오픈 어드레싱(선형 탐사) 두 가지 충돌 처리 방식을 구현합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 hash_table/main.cpp -o ht && ./ht
```

---

## 그래프 (Graph)

**경로:** `graph/`

인접 행렬과 인접 리스트 두 가지 표현 방식을 구현합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 graph/main.cpp -o graph && ./graph
```

---

## 트라이 (Trie)

**경로:** `trie/`

문자열 탐색에 특화된 트리입니다. 자동완성, 접두사 탐색 기능을 포함합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 trie/main.cpp -o trie && ./trie
```

---

## 쿼드트리 (Quad Tree)

**경로:** `quad_tree/`

2D 공간 분할에 사용되는 쿼드트리입니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 quad_tree/main.cpp -o quad_tree && ./quad_tree
```

---

## 🔍 알고리즘 (Algorithms)

## 정렬 (Sorting)

**경로:** `sorting/`

| 파일 | 알고리즘 | 시간 복잡도 |
|---|---|---|
| `bubble_sort.cpp` | 버블 정렬 | O(n²) |
| `selection_sort.cpp` | 선택 정렬 | O(n²) |
| `insertion_sort.cpp` | 삽입 정렬 | O(n²) / O(n) 최선 |
| `merge_sort.cpp` | 합병 정렬 | O(n log n) |
| `quick_sort.cpp` | 퀵 정렬 | O(n log n) 평균 |

### 컴파일 및 실행

```bash
g++ -std=c++17 sorting/bubble_sort.cpp -o bubble && ./bubble
g++ -std=c++17 sorting/merge_sort.cpp -o merge && ./merge
g++ -std=c++17 sorting/quick_sort.cpp -o quick && ./quick
```

---

## 탐색 (Searching)

**경로:** `searching/`

| 파일 | 알고리즘 | 시간 복잡도 |
|---|---|---|
| `linear_search.cpp` | 선형 탐색 | O(n) |
| `binary_search.cpp` | 이진 탐색 (반복/재귀, lower/upper bound) | O(log n) |

### 컴파일 및 실행

```bash
g++ -std=c++17 searching/binary_search.cpp -o binary && ./binary
```

---

## BFS / DFS

**경로:** `bfs_dfs/`

| 파일 | 내용 |
|---|---|
| `bfs.cpp` | 너비 우선 탐색, 최단 거리 계산 |
| `dfs.cpp` | 깊이 우선 탐색 (재귀/반복), 연결 요소 개수 |

### 컴파일 및 실행

```bash
g++ -std=c++17 bfs_dfs/bfs.cpp -o bfs && ./bfs
g++ -std=c++17 bfs_dfs/dfs.cpp -o dfs && ./dfs
```

---

## 재귀 (Recursion)

**경로:** `recursion/`

| 파일 | 내용 |
|---|---|
| `fibonacci.cpp` | 피보나치 (순수 재귀, 메모이제이션, 반복) |
| `factorial.cpp` | 팩토리얼 (재귀, 반복, 꼬리 재귀) |
| `hanoi.cpp` | 하노이 탑 |

### 컴파일 및 실행

```bash
g++ -std=c++17 recursion/hanoi.cpp -o hanoi && ./hanoi
```

---

## 동적 프로그래밍 (Dynamic Programming)

**경로:** `dynamic_programming/`

| 파일 | 내용 |
|---|---|
| `memoization.cpp` | 메모이제이션 (하향식 DP) |
| `tabulation.cpp` | 타뷸레이션 (상향식 DP), LIS, 동전 교환 |
| `lcs.cpp` | 최장 공통 부분 수열 (LCS) |
| `knapsack.cpp` | 0/1 배낭 문제 |

### 컴파일 및 실행

```bash
g++ -std=c++17 dynamic_programming/knapsack.cpp -o knapsack && ./knapsack
```

---

## 📚 C++ 기초 문법

## 포인터 (Pointers)

**경로:** `pointers/`

기본 포인터, 포인터 산술, 이중 포인터, const 포인터, 함수 포인터를 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 pointers/pointers.cpp -o pointers && ./pointers
```

---

## 스마트 포인터 (Smart Pointers)

**경로:** `smart_pointers/`

`unique_ptr`, `shared_ptr`, `weak_ptr`의 사용법과 순환 참조 방지를 설명합니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 smart_pointers/smart_pointers.cpp -o smart_ptr && ./smart_ptr
```

---

## 템플릿 (Templates)

**경로:** `templates/`

함수 템플릿, 클래스 템플릿, 비타입 템플릿 매개변수, 템플릿 특수화를 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 templates/templates.cpp -o templates && ./templates
```

---

## 객체지향 프로그래밍 (OOP)

**경로:** `oop/`

클래스, 상속, 다형성, 가상 함수, 순수 가상 함수, 연산자 오버로딩을 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 oop/oop.cpp -o oop && ./oop
```

---

## STL 기초 (STL Basics)

**경로:** `stl_basics/`

`vector`, `map`, `set`, `unordered_map`과 STL 알고리즘(`sort`, `find`, `transform` 등)을 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 stl_basics/stl_basics.cpp -o stl && ./stl
```

---

## 파일 입출력 (File I/O)

**경로:** `file_io/`

텍스트 파일 읽기/쓰기/추가, CSV 파싱, 이진 파일 입출력을 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 file_io/file_io.cpp -o file_io && ./file_io
```

---

## 예외 처리 (Exception Handling)

**경로:** `exception_handling/`

표준 예외, 사용자 정의 예외, 다중 catch, RAII finally 패턴을 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 exception_handling/exception_handling.cpp -o exception && ./exception
```

---

## 람다 표현식 (Lambda)

**경로:** `lambda/`

람다 기본 문법, 캡처 방식, `std::function`, `std::bind`, STL과의 활용을 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 lambda/lambda.cpp -o lambda && ./lambda
```

---

## 이동 시맨틱 (Move Semantics)

**경로:** `move_semantics/`

lvalue/rvalue 참조, `std::move`, 이동 생성자/대입 연산자, `std::forward`를 다룹니다.

### 컴파일 및 실행

```bash
g++ -std=c++17 move_semantics/move_semantics.cpp -o move && ./move
```

---

## 디렉터리 구조

```
Programming_Language/
├── 📦 자료구조
│   ├── linked_list/          # 단방향 연결 리스트
│   ├── doubly_linked_list/   # 이중 연결 리스트
│   ├── stack/                # 스택 (배열 기반)
│   ├── queue/                # 큐 (원형 배열)
│   ├── circular_queue/       # 원형 큐
│   ├── deque/                # 양방향 큐
│   ├── binary_tree/          # 이진 탐색 트리
│   ├── heap/                 # 최대/최소 힙
│   ├── hash_table/           # 해시 테이블 (체이닝, 오픈 어드레싱)
│   ├── graph/                # 그래프 (인접 행렬/리스트)
│   ├── trie/                 # 트라이
│   └── quad_tree/            # 쿼드트리
├── 🔍 알고리즘
│   ├── sorting/              # 정렬 알고리즘 5종
│   ├── searching/            # 선형/이진 탐색
│   ├── bfs_dfs/              # BFS, DFS
│   ├── recursion/            # 재귀 예제
│   └── dynamic_programming/  # DP 예제
└── 📚 C++ 기초 문법
    ├── pointers/             # 포인터
    ├── smart_pointers/       # 스마트 포인터
    ├── templates/            # 템플릿
    ├── oop/                  # 객체지향 프로그래밍
    ├── stl_basics/           # STL 기초
    ├── file_io/              # 파일 입출력
    ├── exception_handling/   # 예외 처리
    ├── lambda/               # 람다 표현식
    └── move_semantics/       # 이동 시맨틱
```

## 요구 사항

- C++17 이상
- g++ 또는 clang++
