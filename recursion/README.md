# 재귀 (Recursion)

## 개념

재귀는 함수가 **자기 자신을 호출**하는 기법입니다. 모든 재귀는 반복으로 변환 가능합니다.

### 재귀의 두 가지 필수 요소

1. **기저 조건 (Base Case)**: 재귀 호출을 멈추는 조건
2. **재귀 케이스 (Recursive Case)**: 자기 자신을 호출하되 더 작은 문제로 분해

## 포함된 예제

| 파일 | 내용 |
|---|---|
| `fibonacci.cpp` | 피보나치 수열 (순수 재귀, 메모이제이션, 반복) |
| `factorial.cpp` | 팩토리얼 (재귀, 반복, 꼬리 재귀) |
| `hanoi.cpp` | 하노이 탑 (분할 정복 재귀) |

## 컴파일 및 실행

```bash
g++ -std=c++17 recursion/fibonacci.cpp -o fib && ./fib
g++ -std=c++17 recursion/factorial.cpp -o fact && ./fact
g++ -std=c++17 recursion/hanoi.cpp -o hanoi && ./hanoi
```
