# 정렬 알고리즘 (Sorting Algorithms)

## 개요

정렬 알고리즘은 원소들을 특정 순서로 재배열하는 알고리즘입니다.

## 알고리즘 비교

| 알고리즘 | 최선 | 평균 | 최악 | 공간 | 안정성 |
|---|---|---|---|---|---|
| 버블 정렬 | O(n) | O(n²) | O(n²) | O(1) | ✅ 안정 |
| 선택 정렬 | O(n²) | O(n²) | O(n²) | O(1) | ❌ 불안정 |
| 삽입 정렬 | O(n) | O(n²) | O(n²) | O(1) | ✅ 안정 |
| 합병 정렬 | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ 안정 |
| 퀵 정렬 | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ 불안정 |

## 각 파일

| 파일 | 알고리즘 |
|---|---|
| `bubble_sort.cpp` | 버블 정렬 |
| `selection_sort.cpp` | 선택 정렬 |
| `insertion_sort.cpp` | 삽입 정렬 |
| `merge_sort.cpp` | 합병 정렬 (분할 정복) |
| `quick_sort.cpp` | 퀵 정렬 (분할 정복) |

## 컴파일 및 실행

```bash
g++ -std=c++17 sorting/bubble_sort.cpp -o bubble && ./bubble
g++ -std=c++17 sorting/selection_sort.cpp -o selection && ./selection
g++ -std=c++17 sorting/insertion_sort.cpp -o insertion && ./insertion
g++ -std=c++17 sorting/merge_sort.cpp -o merge && ./merge
g++ -std=c++17 sorting/quick_sort.cpp -o quick && ./quick
```
