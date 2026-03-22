# 동적 프로그래밍 (Dynamic Programming)

## 개념

동적 프로그래밍(DP)은 **복잡한 문제를 작은 부분 문제로 나누어 풀고, 그 결과를 저장**하여 중복 계산을 피하는 기법입니다.

### DP의 두 가지 조건

1. **최적 부분 구조** (Optimal Substructure): 전체 최적해가 부분 문제의 최적해로 구성됨
2. **중복 부분 문제** (Overlapping Subproblems): 같은 부분 문제가 반복해서 등장함

## 두 가지 접근 방법

### 메모이제이션 (Memoization) - 하향식 (Top-down)
- 재귀 + 캐시
- 필요한 문제만 계산
- 구현이 직관적

```cpp
unordered_map<int, long long> memo;
long long fib(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```

### 타뷸레이션 (Tabulation) - 상향식 (Bottom-up)
- 반복문 + 테이블
- 모든 부분 문제를 순서대로 계산
- 메모리 효율적

```cpp
vector<long long> dp(n+1);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++)
    dp[i] = dp[i-1] + dp[i-2];
```

## 포함된 예제

| 파일 | 내용 |
|---|---|
| `memoization.cpp` | 피보나치, 격자 경로, 계단 오르기 (메모이제이션) |
| `tabulation.cpp` | 피보나치, LIS, 동전 교환 (타뷸레이션) |
| `lcs.cpp` | 최장 공통 부분 수열 (LCS) |
| `knapsack.cpp` | 0/1 배낭 문제 |

## 컴파일 및 실행

```bash
g++ -std=c++17 dynamic_programming/memoization.cpp -o memo && ./memo
g++ -std=c++17 dynamic_programming/tabulation.cpp -o tab && ./tab
g++ -std=c++17 dynamic_programming/lcs.cpp -o lcs && ./lcs
g++ -std=c++17 dynamic_programming/knapsack.cpp -o knapsack && ./knapsack
```
