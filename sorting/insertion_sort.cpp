#include <iostream>
#include <vector>

// 삽입 정렬 (Insertion Sort)
// 정렬된 부분에 새 원소를 올바른 위치에 삽입
// 시간 복잡도: O(n²) | 공간 복잡도: O(1) | 안정 정렬
// 거의 정렬된 배열에서 매우 효율적 O(n)

void insertion_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // 삽입할 원소
        int j = i - 1;
        // key보다 큰 원소들을 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // 올바른 위치에 삽입
    }
}

void print(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};

    std::cout << "정렬 전: ";
    print(arr);

    insertion_sort(arr);

    std::cout << "정렬 후: ";
    print(arr);  // 5 6 11 12 13

    // 단계별 출력
    std::vector<int> arr2 = {5, 3, 8, 1, 9, 2};
    std::cout << "\n단계별 삽입 정렬:\n";
    int n = arr2.size();
    for (int i = 1; i < n; i++) {
        int key = arr2[i];
        int j = i - 1;
        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j--;
        }
        arr2[j + 1] = key;
        std::cout << "  step " << i << ": ";
        print(arr2);
    }

    return 0;
}
