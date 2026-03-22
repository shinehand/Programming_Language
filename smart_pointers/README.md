# 스마트 포인터 (Smart Pointers)

## 개념

스마트 포인터는 **RAII 패턴**을 사용하여 메모리를 자동으로 관리합니다. 스코프를 벗어나면 자동으로 메모리를 해제합니다.

## 세 가지 스마트 포인터

| 종류 | 소유권 | 복사 | 용도 |
|---|---|---|---|
| `unique_ptr` | 단독 소유 | ❌ (이동만) | 일반 리소스 관리 |
| `shared_ptr` | 공유 소유 | ✅ (참조 카운팅) | 공유 리소스 |
| `weak_ptr` | 비소유 (약한 참조) | ✅ | 순환 참조 방지 |

## 사용법

```cpp
#include <memory>

// unique_ptr
auto p1 = std::make_unique<int>(42);

// shared_ptr
auto p2 = std::make_shared<int>(42);
auto p3 = p2;  // 복사 가능, 참조 카운트 증가

// weak_ptr
std::weak_ptr<int> wp = p2;
if (auto locked = wp.lock()) {  // 사용하려면 lock() 필요
    std::cout << *locked;
}
```

## 컴파일 및 실행

```bash
g++ -std=c++17 smart_pointers/smart_pointers.cpp -o smart_ptr && ./smart_ptr
```
