# 포인터 (Pointers)

## 개념

포인터는 **메모리 주소를 저장**하는 변수입니다. C++에서 포인터는 메모리를 직접 다루는 강력한 도구입니다.

## 기본 문법

```cpp
int x = 42;
int* ptr = &x;   // ptr은 x의 주소를 저장
*ptr = 100;      // 역참조: ptr이 가리키는 값 변경
```

## 포인터 종류

| 선언 | 설명 |
|---|---|
| `int* ptr` | 기본 포인터 |
| `int** pptr` | 이중 포인터 |
| `const int* ptr` | 값 변경 불가 포인터 |
| `int* const ptr` | 주소 변경 불가 포인터 |
| `nullptr` | 널 포인터 (C++11) |

## 컴파일 및 실행

```bash
g++ -std=c++17 pointers/pointers.cpp -o pointers && ./pointers
```
