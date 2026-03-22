# 예외 처리 (Exception Handling)

## 기본 구조

```cpp
try {
    // 예외 발생 가능 코드
    throw std::runtime_error("오류 발생!");
} catch (const std::runtime_error& e) {
    // 런타임 오류 처리
    cout << e.what();
} catch (const std::exception& e) {
    // 모든 표준 예외 처리
} catch (...) {
    // 모든 예외 처리
}
```

## 주요 표준 예외

| 예외 클래스 | 설명 |
|---|---|
| `std::exception` | 모든 표준 예외의 기반 클래스 |
| `std::runtime_error` | 런타임 오류 |
| `std::logic_error` | 논리적 오류 |
| `std::out_of_range` | 범위 초과 |
| `std::invalid_argument` | 잘못된 인자 |
| `std::overflow_error` | 오버플로우 |

## 사용자 정의 예외

```cpp
class MyException : public std::exception {
    const char* what() const noexcept override {
        return "내 예외 메시지";
    }
};
```

## 컴파일 및 실행

```bash
g++ -std=c++17 exception_handling/exception_handling.cpp -o exception && ./exception
```
