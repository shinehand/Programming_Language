#include <iostream>
#include <vector>

// 선택 정렬 (Selection Sort)
// 매 단계마다 남은 원소 중 최솟값을 선택하여 앞으로 이동
// 시간 복잡도: O(n²) | 공간 복잡도: O(1) | 불안정 정렬

void selection_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // 현재 구간에서 최솟값 인덱스
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);  // 최솟값을 앞으로
        }
    }
}

void print(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "정렬 전: ";
    print(arr);

    selection_sort(arr);

    std::cout << "정렬 후: ";
    print(arr);  // 11 12 22 25 64

    // 단계별 출력
    std::vector<int> arr2 = {5, 3, 8, 1, 9, 2};
    std::cout << "\n단계별 선택 정렬:\n";
    int n = arr2.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr2[j] < arr2[min_idx]) min_idx = j;
        }
        std::swap(arr2[i], arr2[min_idx]);
        std::cout << "  step " << i + 1 << ": ";
        print(arr2);
    }

    return 0;
}
