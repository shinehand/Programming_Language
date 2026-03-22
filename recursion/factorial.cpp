#include <iostream>
#include <stdexcept>

// 팩토리얼 (Factorial)
// n! = n × (n-1) × ... × 2 × 1
// 0! = 1

// 1. 재귀 방식
long long factorial_recursive(int n) {
    if (n < 0) throw std::invalid_argument("음수 팩토리얼은 정의되지 않습니다");
    if (n == 0) return 1;  // 기저 조건 (Base case)
    return n * factorial_recursive(n - 1);  // 재귀 호출
}

// 2. 반복 방식
long long factorial_iterative(int n) {
    if (n < 0) throw std::invalid_argument("음수 팩토리얼은 정의되지 않습니다");
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 3. 꼬리 재귀 (Tail Recursion) - 컴파일러 최적화 가능
long long factorial_tail(int n, long long acc = 1) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, n * acc);  // 누적값을 인자로 전달
}

int main() {
    std::cout << "=== 팩토리얼 ===\n";

    for (int i = 0; i <= 10; i++) {
        std::cout << i << "! = " << factorial_recursive(i) << "\n";
    }

    std::cout << "\n재귀와 반복 비교:\n";
    std::cout << "10! 재귀:     " << factorial_recursive(10) << "\n";
    std::cout << "10! 반복:     " << factorial_iterative(10) << "\n";
    std::cout << "10! 꼬리재귀: " << factorial_tail(10) << "\n";

    return 0;
}
