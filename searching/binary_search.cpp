#include <iostream>
#include <vector>
#include <algorithm>  // std::sort, std::lower_bound

// 이진 탐색 (Binary Search)
// 정렬된 배열에서 중간값과 비교하여 탐색 범위를 절반씩 줄여나감
// 시간 복잡도: O(log n) | 정렬 필요: 반드시 정렬된 배열이어야 함

// 반복 방식 이진 탐색
int binary_search_iterative(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 오버플로우 방지

        if (arr[mid] == target) return mid;    // 찾음
        else if (arr[mid] < target) left = mid + 1;  // 오른쪽 탐색
        else right = mid - 1;                  // 왼쪽 탐색
    }
    return -1;  // 없음
}

// 재귀 방식 이진 탐색
int binary_search_recursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target)
        return binary_search_recursive(arr, target, mid + 1, right);
    return binary_search_recursive(arr, target, left, mid - 1);
}

// 하한 (Lower Bound): target 이상의 첫 번째 위치
int lower_bound(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// 상한 (Upper Bound): target 초과의 첫 번째 위치
int upper_bound(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    std::cout << "배열: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n\n";

    // 반복 방식
    std::cout << "=== 반복 이진 탐색 ===\n";
    std::cout << "search(7):  인덱스 " << binary_search_iterative(arr, 7) << "\n";   // 3
    std::cout << "search(15): 인덱스 " << binary_search_iterative(arr, 15) << "\n";  // 7
    std::cout << "search(6):  인덱스 " << binary_search_iterative(arr, 6) << "\n";   // -1

    // 재귀 방식
    std::cout << "\n=== 재귀 이진 탐색 ===\n";
    std::cout << "search(7):  인덱스 " << binary_search_recursive(arr, 7, 0, arr.size()-1) << "\n";
    std::cout << "search(19): 인덱스 " << binary_search_recursive(arr, 19, 0, arr.size()-1) << "\n";

    // 중복 원소에서 Lower/Upper Bound
    std::vector<int> arr2 = {1, 3, 3, 3, 5, 7, 9};
    std::cout << "\n=== Lower/Upper Bound (배열: 1 3 3 3 5 7 9) ===\n";
    std::cout << "lower_bound(3): " << lower_bound(arr2, 3) << "\n";  // 1
    std::cout << "upper_bound(3): " << upper_bound(arr2, 3) << "\n";  // 4
    std::cout << "3의 개수: " << upper_bound(arr2, 3) - lower_bound(arr2, 3) << "\n";  // 3

    // STL 이진 탐색
    std::cout << "\n=== STL 이진 탐색 ===\n";
    auto it = std::lower_bound(arr2.begin(), arr2.end(), 3);
    std::cout << "std::lower_bound(3): 인덱스 " << (it - arr2.begin()) << "\n";

    return 0;
}
