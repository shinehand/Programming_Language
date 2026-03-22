#include <iostream>
#include <vector>

// 타뷸레이션 (Tabulation) - 상향식 DP (Bottom-up)
// 작은 문제부터 순서대로 테이블에 결과를 채워나감

// 예시 1: 피보나치 (타뷸레이션)
long long fib_tab(int n) {
    if (n <= 1) return n;
    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// 예시 2: 최장 증가 부분 수열 (LIS - Longest Increasing Subsequence)
// dp[i] = arr[i]로 끝나는 LIS의 길이
int lis(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> dp(n, 1);  // 각 원소 자체가 길이 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int x : dp) max_len = std::max(max_len, x);
    return max_len;
}

// 예시 3: 동전 교환 (Coin Change)
// amount원을 coins로 만드는 최소 동전 개수
int coin_change(const std::vector<int>& coins, int amount) {
    const int INF = amount + 1;
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;  // 0원은 0개

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
            }
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    std::cout << "=== 타뷸레이션 예제 ===\n\n";

    // 피보나치
    std::cout << "피보나치 DP 테이블 (F(0)~F(10)):\n";
    for (int i = 0; i <= 10; i++) {
        std::cout << "F(" << i << ") = " << fib_tab(i) << "\n";
    }

    // LIS
    std::cout << "\n=== 최장 증가 부분 수열 ===\n";
    std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "배열: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\nLIS 길이: " << lis(arr) << "\n";  // 4 (2,3,7,18 or 2,5,7,18)

    // 동전 교환
    std::cout << "\n=== 동전 교환 ===\n";
    std::vector<int> coins = {1, 5, 10, 25};
    std::cout << "동전: 1, 5, 10, 25원\n";
    std::cout << "41원: " << coin_change(coins, 41) << "개 (25+10+5+1)\n";
    std::cout << "30원: " << coin_change(coins, 30) << "개 (25+5)\n";
    std::cout << "11원: " << coin_change(coins, 11) << "개 (10+1)\n";

    return 0;
}
