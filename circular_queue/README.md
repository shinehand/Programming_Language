# 원형 큐 (Circular Queue)

## 개념

원형 큐는 배열의 끝에 도달하면 **처음으로 돌아가는** 선형 큐의 개선 버전입니다. 일반 선형 큐에서 발생하는 **가짜 포화(false full)** 문제를 해결합니다.

### 구조

```
용량 = 6
index: [0][1][2][3][4][5]
값:    [ ][ ][3][4][5][ ]
              ↑              ↑
           front          back

dequeue → [3] 제거, front 이동
enqueue → back 위치에 삽입, back 이동
```

### 포인터 계산 (나머지 연산 사용)

```cpp
back_idx = (back_idx + 1) % capacity;   // 원형 이동
front_idx = (front_idx + 1) % capacity; // 원형 이동
```

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `enqueue(val)` | 원소 삽입 | O(1) |
| `dequeue()` | 원소 제거 및 반환 | O(1) |
| `front()` | 앞 원소 조회 | O(1) |
| `back()` | 뒤 원소 조회 | O(1) |
| `full()` | 가득 찼는지 확인 | O(1) |
| `empty()` | 비어 있는지 확인 | O(1) |

## 일반 큐와의 비교

| 특성 | 선형 큐 | 원형 큐 |
|---|---|---|
| 가짜 포화 문제 | 있음 | 없음 |
| 메모리 활용 | 비효율적 | 효율적 |
| 구현 복잡도 | 단순 | 약간 복잡 |

## 컴파일 및 실행

```bash
g++ -std=c++17 circular_queue/main.cpp -o circular_queue && ./circular_queue
```
