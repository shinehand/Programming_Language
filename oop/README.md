# 객체지향 프로그래밍 (OOP)

## 4가지 핵심 개념

### 1. 캡슐화 (Encapsulation)
데이터와 메서드를 클래스로 묶고, 접근 제어자로 보호

```cpp
class BankAccount {
private:
    int balance;  // 직접 접근 불가
public:
    void deposit(int amount) { balance += amount; }
    int get_balance() const { return balance; }
};
```

### 2. 상속 (Inheritance)
기존 클래스를 확장하여 새 클래스 생성

```cpp
class Animal { virtual void speak() = 0; };
class Dog : public Animal { void speak() override { cout << "멍!"; } };
```

### 3. 다형성 (Polymorphism)
같은 인터페이스로 다양한 타입 처리

```cpp
Animal* a = new Dog();
a->speak();  // Dog의 speak() 호출 (가상 함수)
```

### 4. 추상화 (Abstraction)
순수 가상 함수로 인터페이스 정의

```cpp
class Shape {
    virtual double area() const = 0;  // 순수 가상 함수
};
```

## 컴파일 및 실행

```bash
g++ -std=c++17 oop/oop.cpp -o oop && ./oop
```
