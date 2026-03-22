#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

// 템플릿 (Templates) - C++의 제네릭 프로그래밍
// 타입에 독립적인 코드를 작성할 수 있게 해줌

// === 함수 템플릿 ===

// 기본 함수 템플릿
template <typename T>
T max_val(T a, T b) {
    return (a > b) ? a : b;
}

// 두 개의 타입 매개변수
template <typename T, typename U>
void print_pair(T first, U second) {
    std::cout << "(" << first << ", " << second << ")\n";
}

// 함수 템플릿 특수화 (Template Specialization)
template <typename T>
std::string type_name() { return "unknown"; }

template <>
std::string type_name<int>() { return "int"; }

template <>
std::string type_name<double>() { return "double"; }

template <>
std::string type_name<std::string>() { return "string"; }

// 가변 인자 템플릿 (Variadic Template) - C++11
template <typename T>
void print_all(T val) {
    std::cout << val << "\n";
}

template <typename T, typename... Args>
void print_all(T first, Args... rest) {
    std::cout << first << " ";
    print_all(rest...);
}

void test_function_templates() {
    std::cout << "=== 함수 템플릿 ===\n";

    std::cout << "max_val(3, 5): " << max_val(3, 5) << "\n";          // int
    std::cout << "max_val(3.14, 2.71): " << max_val(3.14, 2.71) << "\n";  // double
    std::cout << "max_val('a', 'z'): " << max_val('a', 'z') << "\n";  // char

    std::cout << "\nprint_pair: ";
    print_pair(42, "hello");

    std::cout << "\ntype_name: ";
    std::cout << type_name<int>() << ", " << type_name<double>() << ", " << type_name<std::string>() << "\n";

    std::cout << "\nprint_all: ";
    print_all(1, 2.5, "three", 'x');
}

// === 클래스 템플릿 ===

// 간단한 쌍 (Pair) 클래스 템플릿
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 get_first() const { return first; }
    T2 get_second() const { return second; }

    void print() const {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};

// 스택 클래스 템플릿
template <typename T, int MaxSize = 100>
class Stack {
private:
    T data[MaxSize];  // 비타입 템플릿 매개변수
    int top_idx;

public:
    Stack() : top_idx(-1) {}

    void push(const T& val) {
        if (top_idx + 1 >= MaxSize)
            throw std::overflow_error("Stack overflow");
        data[++top_idx] = val;
    }

    T pop() {
        if (top_idx < 0)
            throw std::underflow_error("Stack underflow");
        return data[top_idx--];
    }

    const T& top() const {
        if (top_idx < 0)
            throw std::underflow_error("Stack is empty");
        return data[top_idx];
    }

    bool empty() const { return top_idx == -1; }
    int size() const { return top_idx + 1; }
};

void test_class_templates() {
    std::cout << "\n=== 클래스 템플릿 ===\n";

    // Pair 템플릿
    Pair<int, std::string> p1(1, "one");
    Pair<double, bool> p2(3.14, true);

    std::cout << "Pair<int, string>: ";
    p1.print();
    std::cout << "Pair<double, bool>: ";
    p2.print();

    // Stack 템플릿 (비타입 매개변수)
    Stack<int, 5> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    std::cout << "\nStack<int, 5> top: " << int_stack.top() << "\n";

    Stack<std::string> str_stack;
    str_stack.push("hello");
    str_stack.push("world");
    std::cout << "Stack<string> top: " << str_stack.top() << "\n";
}

// === 템플릿 메타프로그래밍 기초 ===
// 컴파일 시간에 계산하는 기법

// 컴파일 시간 팩토리얼
template <int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template <>  // 기저 조건 특수화
struct Factorial<0> {
    static const int value = 1;
};

// type_traits 예시
template <typename T>
void check_type(T val) {
    std::cout << "값: " << val;
    std::cout << "  is_integral: " << std::is_integral<T>::value;
    std::cout << "  is_floating_point: " << std::is_floating_point<T>::value << "\n";
}

void test_meta_programming() {
    std::cout << "\n=== 템플릿 메타프로그래밍 ===\n";

    // 컴파일 시간 상수
    std::cout << "Factorial<5> = " << Factorial<5>::value << "\n";  // 120
    std::cout << "Factorial<10> = " << Factorial<10>::value << "\n"; // 3628800

    // type_traits
    check_type(42);
    check_type(3.14);
    check_type('A');
}

int main() {
    test_function_templates();
    test_class_templates();
    test_meta_programming();

    return 0;
}
