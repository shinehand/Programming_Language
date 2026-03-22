#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// 0/1 배낭 문제 (0/1 Knapsack Problem)
// n개의 물건과 최대 용량 W인 배낭
// 각 물건은 무게(weight)와 가치(value)를 가짐
// 물건을 담거나(1) 안 담거나(0) 선택 → 최대 가치 구하기

struct Item {
    std::string name;
    int weight;
    int value;
};

// 0/1 배낭 문제 풀이
// dp[i][w] = i번째 물건까지 고려했을 때, 무게 w로 얻을 수 있는 최대 가치
int knapsack(const std::vector<Item>& items, int W) {
    int n = items.size();
    // dp 테이블 초기화 (n+1 x W+1)
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // 현재 물건을 담지 않는 경우
            dp[i][w] = dp[i-1][w];

            // 현재 물건을 담는 경우 (무게가 충분하면)
            if (items[i-1].weight <= w) {
                int with_item = dp[i-1][w - items[i-1].weight] + items[i-1].value;
                dp[i][w] = std::max(dp[i][w], with_item);
            }
        }
    }
    return dp[n][W];
}

// 어떤 물건을 담았는지 역추적
std::vector<std::string> knapsack_items(const std::vector<Item>& items, int W) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (items[i-1].weight <= w) {
                int with_item = dp[i-1][w - items[i-1].weight] + items[i-1].value;
                dp[i][w] = std::max(dp[i][w], with_item);
            }
        }
    }

    // 역추적
    std::vector<std::string> selected;
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(items[i-1].name);
            w -= items[i-1].weight;
        }
    }
    return selected;
}

int main() {
    std::cout << "=== 0/1 배낭 문제 ===\n\n";

    std::vector<Item> items = {
        {"노트북", 3, 4},
        {"핸드폰", 1, 3},
        {"카메라", 2, 3},
        {"책",    2, 1},
        {"시계",  1, 2}
    };

    int W = 5;  // 배낭 최대 용량

    std::cout << "물건 목록:\n";
    std::cout << "이름\t무게\t가치\n";
    for (const auto& item : items) {
        std::cout << item.name << "\t" << item.weight << "\t" << item.value << "\n";
    }
    std::cout << "\n배낭 용량: " << W << "\n";

    int max_value = knapsack(items, W);
    std::cout << "최대 가치: " << max_value << "\n";

    auto selected = knapsack_items(items, W);
    std::cout << "선택된 물건: ";
    for (const auto& name : selected) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    return 0;
}
