#include <iostream>
#include <vector>

// 퀵 정렬 (Quick Sort)
// 피벗을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 분할
// 시간 복잡도: O(n log n) 평균, O(n²) 최악 | 공간 복잡도: O(log n) | 불안정 정렬

// 피벗을 기준으로 배열 분할
// 피벗보다 작은 원소는 왼쪽, 큰 원소는 오른쪽
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 마지막 원소를 피벗으로 선택
    int i = low - 1;         // 작은 원소의 경계

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);  // 작은 원소를 왼쪽으로
        }
    }
    std::swap(arr[i + 1], arr[high]);  // 피벗을 올바른 위치에
    return i + 1;                      // 피벗의 최종 위치 반환
}

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivot_idx = partition(arr, low, high);  // 분할
    quick_sort(arr, low, pivot_idx - 1);         // 왼쪽 재귀
    quick_sort(arr, pivot_idx + 1, high);        // 오른쪽 재귀
}

void print(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};

    std::cout << "정렬 전: ";
    print(arr);

    quick_sort(arr, 0, arr.size() - 1);

    std::cout << "정렬 후: ";
    print(arr);  // 1 5 7 8 9 10

    // 중복 원소 포함 테스트
    std::vector<int> arr2 = {3, 6, 8, 10, 1, 2, 1};
    quick_sort(arr2, 0, arr2.size() - 1);
    std::cout << "중복 포함: ";
    print(arr2);  // 1 1 2 3 6 8 10

    return 0;
}
