#include <iostream>
#include <unordered_map>

// 피보나치 수열 (Fibonacci Sequence)
// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

// 1. 순수 재귀 - 시간 복잡도 O(2^n) (비효율적, 중복 계산)
long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// 2. 메모이제이션 (Memoization) - 시간 복잡도 O(n)
std::unordered_map<int, long long> memo;
long long fib_memo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];  // 캐시 확인
    return memo[n] = fib_memo(n - 1) + fib_memo(n - 2);  // 결과 저장
}

// 3. 반복 (Iterative) - 시간 복잡도 O(n), 공간 복잡도 O(1)
long long fib_iterative(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        long long cur = prev2 + prev1;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << "=== 피보나치 수열 ===\n";

    // 처음 10개 출력
    std::cout << "F(0)~F(9): ";
    for (int i = 0; i < 10; i++) {
        std::cout << fib_iterative(i) << " ";
    }
    std::cout << "\n";

    // 방법 비교
    std::cout << "\nF(10) 재귀:       " << fib_recursive(10) << "\n";
    std::cout << "F(10) 메모이제이션: " << fib_memo(10) << "\n";
    std::cout << "F(10) 반복:       " << fib_iterative(10) << "\n";

    // 큰 값 (메모이제이션/반복만 가능)
    std::cout << "\nF(40) 메모이제이션: " << fib_memo(40) << "\n";
    std::cout << "F(50) 반복:       " << fib_iterative(50) << "\n";

    return 0;
}
