#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

// 람다 표현식 (Lambda Expressions) - C++11
// 익명 함수를 인라인으로 정의하는 문법

void demonstrate_basic_lambda() {
    std::cout << "=== 기본 람다 ===\n";

    // 기본 람다 문법: [캡처](매개변수) -> 반환타입 { 함수 본체 }

    // 단순 람다
    auto greet = []() { std::cout << "안녕하세요!\n"; };
    greet();

    // 매개변수 있는 람다
    auto add = [](int a, int b) -> int { return a + b; };
    std::cout << "add(3, 4) = " << add(3, 4) << "\n";

    // 반환 타입 추론 (auto)
    auto multiply = [](double a, double b) { return a * b; };
    std::cout << "multiply(2.5, 4.0) = " << multiply(2.5, 4.0) << "\n";

    // 즉시 호출 (IIFE: Immediately Invoked Function Expression)
    int result = [](int x) { return x * x; }(7);
    std::cout << "7의 제곱: " << result << "\n";
}

void demonstrate_capture() {
    std::cout << "\n=== 캡처 (Capture) ===\n";

    int x = 10, y = 20;

    // [=] 값으로 복사 캡처 (수정 불가)
    auto by_value = [=]() {
        std::cout << "값 캡처 - x: " << x << ", y: " << y << "\n";
    };
    by_value();

    // [&] 참조로 캡처 (수정 가능)
    auto by_ref = [&]() {
        x += 5;  // 외부 변수 수정 가능
        std::cout << "참조 캡처 - x: " << x << "\n";
    };
    by_ref();
    std::cout << "외부 x: " << x << "\n";  // 수정됨 (15)

    // [=] mutable: 복사 캡처지만 수정 가능 (외부에는 영향 없음)
    int z = 100;
    auto mutable_capture = [=]() mutable {
        z += 999;  // 복사본만 수정
        std::cout << "mutable 캡처 - z: " << z << "\n";
    };
    mutable_capture();
    std::cout << "외부 z: " << z << "\n";  // 변경 없음 (100)

    // 특정 변수만 캡처
    int a = 1, b = 2;
    auto specific = [a, &b]() {
        // a는 값 캡처, b는 참조 캡처
        std::cout << "a=" << a << ", b=" << b << "\n";
        b = 99;  // 참조 캡처이므로 수정 가능
    };
    specific();
    std::cout << "외부 b: " << b << "\n";  // 99
}

void demonstrate_std_function() {
    std::cout << "\n=== std::function ===\n";

    // std::function: 함수, 람다, 함수 포인터를 담는 범용 타입
    std::function<int(int, int)> op;

    op = [](int a, int b) { return a + b; };
    std::cout << "덧셈: " << op(3, 4) << "\n";

    op = [](int a, int b) { return a * b; };
    std::cout << "곱셈: " << op(3, 4) << "\n";

    // 함수 포인터도 저장 가능
    auto subtract = [](int a, int b) { return a - b; };
    op = subtract;
    std::cout << "뺄셈: " << op(10, 3) << "\n";

    // 고차 함수 (Higher-order function): 함수를 인자로 받기
    auto apply = [](std::function<int(int)> f, int val) {
        return f(val);
    };

    std::cout << "apply(x²+1, 5) = " << apply([](int x) { return x*x + 1; }, 5) << "\n";
}

void demonstrate_lambda_with_stl() {
    std::cout << "\n=== STL과 람다 ===\n";

    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 조건부 정렬
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });  // 내림차순
    std::cout << "내림차순: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // 조건 필터 (짝수만 출력)
    std::cout << "짝수: ";
    std::for_each(v.begin(), v.end(), [](int x) {
        if (x % 2 == 0) std::cout << x << " ";
    });
    std::cout << "\n";

    // count_if
    int even_count = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "짝수 개수: " << even_count << "\n";

    // transform (제곱)
    std::vector<int> squared;
    std::transform(v.begin(), v.end(), std::back_inserter(squared),
                   [](int x) { return x * x; });
    std::cout << "제곱: ";
    for (int x : squared) std::cout << x << " ";
    std::cout << "\n";
}

void demonstrate_std_bind() {
    std::cout << "\n=== std::bind ===\n";

    // std::bind: 함수의 인자를 미리 고정 (부분 적용)
    auto add = [](int a, int b) { return a + b; };

    // 첫 번째 인자를 10으로 고정
    auto add10 = std::bind(add, 10, std::placeholders::_1);
    std::cout << "add10(5) = " << add10(5) << "\n";   // 15
    std::cout << "add10(20) = " << add10(20) << "\n"; // 30

    // 인자 순서 변경
    auto subtract = [](int a, int b) { return a - b; };
    auto subtract_from_100 = std::bind(subtract, 100, std::placeholders::_1);
    std::cout << "100 - 30 = " << subtract_from_100(30) << "\n";
}

int main() {
    demonstrate_basic_lambda();
    demonstrate_capture();
    demonstrate_std_function();
    demonstrate_lambda_with_stl();
    demonstrate_std_bind();

    return 0;
}
