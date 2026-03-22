#include <iostream>
#include <string>
#include <vector>
#include <memory>

// OOP (Object-Oriented Programming) - 객체지향 프로그래밍
// 클래스, 상속, 다형성, 가상 함수

// === 1. 클래스 기초 ===
class Animal {
protected:  // 자식 클래스에서 접근 가능
    std::string name;
    int age;

public:
    // 생성자
    Animal(const std::string& n, int a) : name(n), age(a) {
        std::cout << "  Animal 생성: " << name << "\n";
    }

    // 가상 소멸자 (다형성 사용 시 필수)
    virtual ~Animal() {
        std::cout << "  Animal 소멸: " << name << "\n";
    }

    // 가상 함수 (Virtual Function) - 파생 클래스에서 재정의 가능
    virtual void speak() const {
        std::cout << name << ": (소리 없음)\n";
    }

    // 순수 가상 함수 (Pure Virtual Function) - 반드시 재정의해야 함
    virtual std::string type() const = 0;

    // 일반 멤버 함수
    void info() const {
        std::cout << "이름: " << name << ", 나이: " << age << ", 종류: " << type() << "\n";
    }

    std::string get_name() const { return name; }
};

// === 2. 상속 (Inheritance) ===
class Dog : public Animal {
private:
    std::string breed;  // 품종

public:
    Dog(const std::string& n, int a, const std::string& b)
        : Animal(n, a), breed(b) {
        std::cout << "  Dog 생성: " << name << " (" << breed << ")\n";
    }

    ~Dog() override {
        std::cout << "  Dog 소멸: " << name << "\n";
    }

    // 가상 함수 재정의 (Override)
    void speak() const override {
        std::cout << name << ": 멍멍!\n";
    }

    std::string type() const override { return "개"; }

    void fetch() const {
        std::cout << name << ": 공을 가져옵니다!\n";
    }
};

class Cat : public Animal {
private:
    bool is_indoor;

public:
    Cat(const std::string& n, int a, bool indoor)
        : Animal(n, a), is_indoor(indoor) {
        std::cout << "  Cat 생성: " << name << "\n";
    }

    ~Cat() override {
        std::cout << "  Cat 소멸: " << name << "\n";
    }

    void speak() const override {
        std::cout << name << ": 야옹~\n";
    }

    std::string type() const override { return "고양이"; }

    void purr() const {
        std::cout << name << ": 그르릉...\n";
    }
};

// === 3. 다중 상속 ===
class FlyingAnimal {
public:
    virtual void fly() const {
        std::cout << "날고 있습니다!\n";
    }
    virtual ~FlyingAnimal() = default;
};

class Bird : public Animal, public FlyingAnimal {
public:
    Bird(const std::string& n, int a) : Animal(n, a) {}

    void speak() const override {
        std::cout << name << ": 짹짹!\n";
    }

    std::string type() const override { return "새"; }

    void fly() const override {
        std::cout << name << ": 하늘을 납니다!\n";
    }
};

// === 4. 연산자 오버로딩 ===
class Vector2D {
public:
    double x, y;

    Vector2D(double x, double y) : x(x), y(y) {}

    // + 연산자 오버로딩
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // == 연산자 오버로딩
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    // << 연산자 오버로딩 (출력)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

void test_polymorphism() {
    std::cout << "=== 다형성 (Polymorphism) ===\n";

    // 기본 클래스 포인터로 다양한 파생 클래스 사용
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("바둑이", 3, "진돗개"));
    animals.push_back(std::make_unique<Cat>("나비", 2, true));
    animals.push_back(std::make_unique<Bird>("참새", 1));

    std::cout << "\n모든 동물 정보:\n";
    for (const auto& animal : animals) {
        animal->info();
    }

    std::cout << "\n모든 동물 소리:\n";
    for (const auto& animal : animals) {
        animal->speak();
    }

    std::cout << "\n동물들 소멸:\n";
}

void test_operator_overloading() {
    std::cout << "\n=== 연산자 오버로딩 ===\n";

    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2;

    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "v1 + v2: " << v3 << "\n";
    std::cout << "v1 == v2: " << (v1 == v2 ? "같음" : "다름") << "\n";
}

int main() {
    test_polymorphism();
    test_operator_overloading();

    return 0;
}
