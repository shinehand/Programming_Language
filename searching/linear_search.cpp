#include <iostream>
#include <vector>

// 선형 탐색 (Linear Search)
// 처음부터 순서대로 찾을 때까지 탐색
// 시간 복잡도: O(n) | 정렬 여부: 상관없음

// 첫 번째 일치 인덱스 반환 (없으면 -1)
int linear_search(const std::vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// 모든 일치 인덱스 반환
std::vector<int> linear_search_all(const std::vector<int>& arr, int target) {
    std::vector<int> result;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) result.push_back(i);
    }
    return result;
}

int main() {
    std::vector<int> arr = {5, 3, 8, 1, 9, 2, 8, 4, 7};

    std::cout << "배열: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    // 단일 탐색
    int idx = linear_search(arr, 8);
    std::cout << "linear_search(8): 인덱스 " << idx << "\n";  // 2

    idx = linear_search(arr, 10);
    std::cout << "linear_search(10): 인덱스 " << idx << "\n"; // -1 (없음)

    // 전체 탐색
    auto indices = linear_search_all(arr, 8);
    std::cout << "linear_search_all(8): 인덱스 ";
    for (int i : indices) std::cout << i << " ";  // 2 6
    std::cout << "\n";

    return 0;
}
