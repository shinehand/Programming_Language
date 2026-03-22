#include <iostream>
#include <unordered_map>
#include <vector>

// 메모이제이션 (Memoization) - 하향식 DP (Top-down)
// 재귀 + 캐시: 이미 계산한 결과를 저장하여 중복 계산 방지

// 예시 1: 피보나치 (메모이제이션)
std::unordered_map<int, long long> fib_cache;
long long fib(int n) {
    if (n <= 1) return n;
    if (fib_cache.count(n)) return fib_cache[n];
    return fib_cache[n] = fib(n - 1) + fib(n - 2);
}

// 예시 2: 격자 경로 수 (Grid Paths)
// m x n 격자에서 좌상단에서 우하단까지 가는 경우의 수
// 오른쪽 또는 아래로만 이동 가능
std::unordered_map<int, long long> grid_cache;
long long grid_paths(int m, int n) {
    if (m == 1 || n == 1) return 1;  // 한 행 또는 한 열이면 경우의 수 1
    int key = m * 1000 + n;  // 유일한 키 생성
    if (grid_cache.count(key)) return grid_cache[key];
    return grid_cache[key] = grid_paths(m - 1, n) + grid_paths(m, n - 1);
}

// 예시 3: 계단 오르기 (Climbing Stairs)
// n개의 계단을 1칸 또는 2칸씩 오르는 방법의 수
std::unordered_map<int, int> stair_cache;
int climb_stairs(int n) {
    if (n <= 2) return n;
    if (stair_cache.count(n)) return stair_cache[n];
    return stair_cache[n] = climb_stairs(n - 1) + climb_stairs(n - 2);
}

int main() {
    std::cout << "=== 메모이제이션 예제 ===\n\n";

    // 피보나치
    std::cout << "피보나치 F(30) = " << fib(30) << "\n";
    std::cout << "피보나치 F(50) = " << fib(50) << "\n";

    // 격자 경로
    std::cout << "\n격자 경로 수:\n";
    std::cout << "2x2 격자: " << grid_paths(2, 2) << "\n";  // 2
    std::cout << "3x3 격자: " << grid_paths(3, 3) << "\n";  // 6
    std::cout << "4x4 격자: " << grid_paths(4, 4) << "\n";  // 20

    // 계단 오르기
    std::cout << "\n계단 오르기:\n";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << "칸: " << climb_stairs(i) << "가지\n";
    }

    return 0;
}
