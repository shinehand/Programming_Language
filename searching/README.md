# 탐색 알고리즘 (Searching Algorithms)

## 선형 탐색 (Linear Search)

처음부터 끝까지 순서대로 탐색합니다.

- **시간 복잡도**: O(n)
- **정렬 필요**: 없음
- **장점**: 정렬 불필요, 구현 간단
- **단점**: 느림

## 이진 탐색 (Binary Search)

**정렬된 배열**에서 중간값과 비교하며 탐색 범위를 절반으로 줄입니다.

```
target = 7, arr = [1, 3, 5, 7, 9, 11, 13]
                        ↑ mid=5
7 > 5 → 오른쪽 탐색
        [7, 9, 11, 13]
         ↑ mid=9
7 < 9 → 왼쪽 탐색
        [7]
         ↑ 찾음!
```

- **시간 복잡도**: O(log n)
- **정렬 필요**: 반드시 정렬되어 있어야 함

## 비교

| 알고리즘 | 시간 복잡도 | 정렬 필요 | 구현 |
|---|---|---|---|
| 선형 탐색 | O(n) | ❌ | 간단 |
| 이진 탐색 | O(log n) | ✅ | 약간 복잡 |

## 컴파일 및 실행

```bash
g++ -std=c++17 searching/linear_search.cpp -o linear && ./linear
g++ -std=c++17 searching/binary_search.cpp -o binary && ./binary
```
