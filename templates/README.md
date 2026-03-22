# 템플릿 (Templates)

## 개념

템플릿은 **타입에 독립적인 코드**를 작성할 수 있는 C++의 제네릭 프로그래밍 기법입니다.

## 함수 템플릿

```cpp
template <typename T>
T max_val(T a, T b) {
    return (a > b) ? a : b;
}

max_val(3, 5);       // int 버전 자동 생성
max_val(3.14, 2.71); // double 버전 자동 생성
```

## 클래스 템플릿

```cpp
template <typename T>
class Stack {
    T data[100];
    // ...
};

Stack<int> intStack;
Stack<string> strStack;
```

## 컴파일 및 실행

```bash
g++ -std=c++17 templates/templates.cpp -o templates && ./templates
```
