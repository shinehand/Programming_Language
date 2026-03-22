#include <iostream>
#include <vector>

// 합병 정렬 (Merge Sort)
// 분할 정복: 배열을 반으로 나누고, 각각 정렬 후 합병
// 시간 복잡도: O(n log n) | 공간 복잡도: O(n) | 안정 정렬

// 두 정렬된 부분 배열을 합병
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // 임시 배열 생성
    std::vector<int> temp(right - left + 1);

    int i = left;    // 왼쪽 부분 시작
    int j = mid + 1; // 오른쪽 부분 시작
    int k = 0;       // 임시 배열 인덱스

    // 두 부분을 비교하며 합병
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 남은 원소 복사
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // 임시 배열을 원본에 복사
    for (int idx = 0; idx < k; idx++) {
        arr[left + idx] = temp[idx];
    }
}

// 재귀적 분할
void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;  // 원소가 1개이면 이미 정렬됨

    int mid = left + (right - left) / 2;  // 오버플로우 방지
    merge_sort(arr, left, mid);           // 왼쪽 반 정렬
    merge_sort(arr, mid + 1, right);      // 오른쪽 반 정렬
    merge(arr, left, mid, right);         // 합병
}

void print(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "정렬 전: ";
    print(arr);

    merge_sort(arr, 0, arr.size() - 1);

    std::cout << "정렬 후: ";
    print(arr);  // 3 9 10 27 38 43 82

    // 다양한 케이스 테스트
    std::vector<int> arr2 = {1};
    merge_sort(arr2, 0, arr2.size() - 1);
    std::cout << "단일 원소: ";
    print(arr2);

    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    merge_sort(arr3, 0, arr3.size() - 1);
    std::cout << "역순 정렬: ";
    print(arr3);

    return 0;
}
