#include <iostream>
#include <vector>

// 버블 정렬 (Bubble Sort)
// 인접한 두 원소를 비교하여 큰 것을 뒤로 보내는 방식
// 시간 복잡도: O(n²) | 공간 복잡도: O(1) | 안정 정렬

void bubble_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // 최적화: 교환이 없으면 이미 정렬됨
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // 정렬 완료 조기 종료
    }
}

void print(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "정렬 전: ";
    print(arr);

    bubble_sort(arr);

    std::cout << "정렬 후: ";
    print(arr);  // 11 12 22 25 34 64 90

    // 이미 정렬된 배열 (조기 종료 최적화 확인)
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    bubble_sort(sorted);
    std::cout << "이미 정렬된 배열: ";
    print(sorted);

    return 0;
}
