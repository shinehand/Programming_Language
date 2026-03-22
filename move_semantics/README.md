# 이동 시맨틱 (Move Semantics)

## 개념

이동 시맨틱은 **불필요한 복사를 제거**하여 성능을 향상시키는 C++11 기능입니다.

## lvalue vs rvalue

| 구분 | 설명 | 예시 |
|---|---|---|
| lvalue | 이름이 있는 표현식 | `int x = 5;` → x |
| rvalue | 임시 값, 이름 없음 | `5`, `x + 3`, `string("hi")` |

## 핵심 개념

### rvalue 참조 (&&)

```cpp
int&& r = 42;        // rvalue 참조
int&& r2 = std::move(x);  // lvalue를 rvalue로 변환
```

### 이동 생성자

```cpp
Buffer(Buffer&& other) noexcept {
    data = other.data;  // 포인터 이동 (복사 없음)
    other.data = nullptr;  // 원본 무효화
}
```

## std::move vs std::forward

| 함수 | 설명 |
|---|---|
| `std::move(x)` | x를 rvalue로 변환 (이동 의도 표현) |
| `std::forward<T>(x)` | 완벽한 전달 (값 카테고리 보존) |

## 컴파일 및 실행

```bash
g++ -std=c++17 move_semantics/move_semantics.cpp -o move && ./move
```
