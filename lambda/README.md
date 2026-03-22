# 람다 표현식 (Lambda Expressions)

## 문법

```cpp
[캡처](매개변수) -> 반환타입 { 함수 본체 }
```

## 캡처 방식

| 캡처 | 설명 |
|---|---|
| `[]` | 캡처 없음 |
| `[=]` | 외부 변수를 값으로 복사 |
| `[&]` | 외부 변수를 참조로 캡처 |
| `[x]` | 변수 x만 값으로 캡처 |
| `[&x]` | 변수 x만 참조로 캡처 |
| `[=, &x]` | 기본 값 캡처, x만 참조 |

## std::function

```cpp
#include <functional>
std::function<int(int, int)> op;
op = [](int a, int b) { return a + b; };
op(3, 4);  // 7
```

## 컴파일 및 실행

```bash
g++ -std=c++17 lambda/lambda.cpp -o lambda && ./lambda
```
