#include <iostream>

// 포인터 (Pointers) - C++의 핵심 개념
// 포인터는 메모리 주소를 저장하는 변수

void demonstrate_basic_pointers() {
    std::cout << "=== 기본 포인터 ===\n";

    int x = 42;
    int* ptr = &x;  // ptr은 x의 주소를 가리킴

    std::cout << "x의 값: " << x << "\n";
    std::cout << "x의 주소: " << &x << "\n";
    std::cout << "ptr의 값(주소): " << ptr << "\n";
    std::cout << "ptr이 가리키는 값: " << *ptr << "\n";  // 역참조 (dereference)

    // 포인터를 통한 값 변경
    *ptr = 100;
    std::cout << "포인터로 변경 후 x: " << x << "\n";  // 100
}

void demonstrate_pointer_arithmetic() {
    std::cout << "\n=== 포인터 산술 ===\n";

    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // 배열의 첫 번째 원소를 가리킴

    std::cout << "배열 원소들 (포인터 산술 이용):\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  arr[" << i << "] = " << *(ptr + i)
                  << "  (주소: " << (ptr + i) << ")\n";
    }

    // 포인터 증감
    std::cout << "*ptr:     " << *ptr << "\n";      // 10
    std::cout << "*(ptr+1): " << *(ptr + 1) << "\n"; // 20
    ptr++;  // 다음 원소로 이동
    std::cout << "ptr++ 후: " << *ptr << "\n";       // 20

    // 포인터 차이
    int* end = arr + 5;
    std::cout << "포인터 차이: " << (end - arr) << "\n";  // 5
}

void demonstrate_null_pointer() {
    std::cout << "\n=== 널 포인터 ===\n";

    int* ptr = nullptr;  // C++11: nullptr 사용 권장 (C에서는 NULL)
    std::cout << "nullptr: " << ptr << "\n";

    if (ptr == nullptr) {
        std::cout << "포인터가 nullptr입니다 (안전)\n";
    }

    // 역참조 전 반드시 null 체크
    if (ptr) {  // nullptr은 false로 평가됨
        std::cout << "역참조 가능\n";
    } else {
        std::cout << "역참조 불가 (nullptr)\n";
    }
}

void demonstrate_double_pointer() {
    std::cout << "\n=== 이중 포인터 ===\n";

    int x = 10;
    int* ptr = &x;     // 포인터
    int** pptr = &ptr; // 포인터의 포인터 (이중 포인터)

    std::cout << "x: " << x << "\n";
    std::cout << "*ptr: " << *ptr << "\n";
    std::cout << "**pptr: " << **pptr << "\n";

    // 이중 포인터로 값 변경
    **pptr = 999;
    std::cout << "**pptr = 999 후 x: " << x << "\n";  // 999

    // 2D 배열 시뮬레이션
    std::cout << "\n이중 포인터로 2D 배열:\n";
    int rows = 3, cols = 3;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // 메모리 해제
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
}

void demonstrate_const_pointer() {
    std::cout << "\n=== const 포인터 ===\n";

    int x = 10, y = 20;

    // 포인터 상수 (포인터가 가리키는 값 변경 불가)
    const int* ptr1 = &x;
    // *ptr1 = 100;  // 오류! 값 변경 불가
    ptr1 = &y;       // 포인터 자체는 변경 가능
    std::cout << "const int* ptr1: " << *ptr1 << "\n";

    // 상수 포인터 (포인터 자체 변경 불가)
    int* const ptr2 = &x;
    *ptr2 = 100;     // 값 변경 가능
    // ptr2 = &y;    // 오류! 포인터 변경 불가
    std::cout << "int* const ptr2: " << *ptr2 << "\n";

    // 완전 상수 포인터 (둘 다 변경 불가)
    const int* const ptr3 = &x;
    std::cout << "const int* const ptr3: " << *ptr3 << "\n";
}

// 함수 포인터 (Function Pointer)
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

void demonstrate_function_pointer() {
    std::cout << "\n=== 함수 포인터 ===\n";

    // 함수 포인터 선언: 반환타입 (*이름)(매개변수 타입들)
    int (*op)(int, int);

    op = add;
    std::cout << "add(3, 4) = " << op(3, 4) << "\n";

    op = subtract;
    std::cout << "subtract(10, 3) = " << op(10, 3) << "\n";

    op = multiply;
    std::cout << "multiply(5, 6) = " << op(5, 6) << "\n";

    // 함수 포인터 배열
    int (*ops[])(int, int) = {add, subtract, multiply};
    std::string names[] = {"add", "subtract", "multiply"};
    for (int i = 0; i < 3; i++) {
        std::cout << names[i] << "(10, 3) = " << ops[i](10, 3) << "\n";
    }
}

int main() {
    demonstrate_basic_pointers();
    demonstrate_pointer_arithmetic();
    demonstrate_null_pointer();
    demonstrate_double_pointer();
    demonstrate_const_pointer();
    demonstrate_function_pointer();

    return 0;
}
