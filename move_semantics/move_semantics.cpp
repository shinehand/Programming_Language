#include <iostream>
#include <string>
#include <vector>
#include <utility>  // std::move

// 이동 시맨틱 (Move Semantics) - C++11
// rvalue 참조와 std::move를 사용한 효율적인 리소스 이동

// === lvalue vs rvalue ===
// lvalue: 이름이 있고 주소를 가질 수 있는 표현식 (int x = 5; → x는 lvalue)
// rvalue: 임시 값, 이름이 없음 (5, 3+4, string("hello"))

void demonstrate_lvalue_rvalue() {
    std::cout << "=== lvalue vs rvalue ===\n";

    int x = 5;       // x는 lvalue, 5는 rvalue
    int y = x + 3;   // y는 lvalue, x+3은 rvalue
    (void)y;

    // lvalue 참조
    int& lref = x;
    lref = 100;
    std::cout << "lvalue 참조: x = " << x << "\n";  // 100

    // rvalue 참조 (&&)
    int&& rref = 42;  // rvalue를 rvalue 참조로 바인딩
    rref = 200;       // rvalue 참조는 수정 가능
    std::cout << "rvalue 참조: " << rref << "\n";

    // std::move: lvalue를 rvalue로 변환
    int z = 10;
    int&& rref2 = std::move(z);  // z를 rvalue로 변환
    std::cout << "std::move 후 rref2: " << rref2 << "\n";
}

// === 이동 생성자와 이동 대입 연산자 ===
class Buffer {
private:
    int* data;
    int size;

public:
    // 생성자
    Buffer(int sz) : size(sz), data(new int[sz]) {
        std::cout << "  생성자 호출 (크기: " << size << ")\n";
        for (int i = 0; i < size; i++) data[i] = i;
    }

    // 복사 생성자 (깊은 복사)
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::cout << "  복사 생성자 호출 (크기: " << size << ")\n";
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    // 이동 생성자 (자원 이동, 복사 없음)
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        std::cout << "  이동 생성자 호출 (크기: " << size << ")\n";
        other.data = nullptr;  // 원본의 포인터를 무효화
        other.size = 0;
    }

    // 복사 대입 연산자
    Buffer& operator=(const Buffer& other) {
        std::cout << "  복사 대입 호출\n";
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this;
    }

    // 이동 대입 연산자
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "  이동 대입 호출\n";
        if (this != &other) {
            delete[] data;
            data = other.data;  // 포인터만 이동
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Buffer() {
        if (data) {
            std::cout << "  소멸자 호출 (크기: " << size << ")\n";
            delete[] data;
        } else {
            std::cout << "  소멸자 호출 (이동됨, 크기: 0)\n";
        }
    }

    int get_size() const { return size; }
    bool is_valid() const { return data != nullptr; }

    void print() const {
        if (!data) { std::cout << "  [이동됨, 데이터 없음]\n"; return; }
        std::cout << "  데이터 [0.." << (size-1) << "]: ";
        for (int i = 0; i < std::min(size, 5); i++) std::cout << data[i] << " ";
        if (size > 5) std::cout << "...";
        std::cout << "\n";
    }
};

void demonstrate_move_constructor() {
    std::cout << "\n=== 이동 생성자 ===\n";

    std::cout << "[복사 생성]:\n";
    Buffer b1(5);
    Buffer b2 = b1;  // 복사 생성자
    std::cout << "b1 유효: " << b1.is_valid() << "\n";
    std::cout << "b2 유효: " << b2.is_valid() << "\n";

    std::cout << "\n[이동 생성]:\n";
    Buffer b3(5);
    Buffer b4 = std::move(b3);  // 이동 생성자
    std::cout << "b3 유효 (이동 후): " << b3.is_valid() << "\n";  // 0
    std::cout << "b4 유효: " << b4.is_valid() << "\n";            // 1
    b4.print();

    std::cout << "\n[소멸]:\n";
}

void demonstrate_move_in_vector() {
    std::cout << "\n=== vector에서의 이동 ===\n";

    std::cout << "push_back(rvalue):\n";
    std::vector<Buffer> vec;
    vec.reserve(3);  // 재할당 방지
    vec.push_back(Buffer(3));  // 임시 객체 → 이동
    vec.push_back(Buffer(4));
    vec.push_back(Buffer(5));

    std::cout << "\nemplace_back (직접 생성):\n";
    std::vector<Buffer> vec2;
    vec2.reserve(2);
    vec2.emplace_back(3);  // 가장 효율적: 복사/이동 없이 직접 생성
    vec2.emplace_back(4);

    std::cout << "\n[소멸]:\n";
}

int main() {
    demonstrate_lvalue_rvalue();
    demonstrate_move_constructor();
    demonstrate_move_in_vector();

    std::cout << "\n=== std::move 활용 (string) ===\n";
    std::string s1 = "안녕하세요, 긴 문자열입니다!";
    std::cout << "이동 전 s1: " << s1 << "\n";

    std::string s2 = std::move(s1);  // s1 → s2 이동 (복사 없음)
    std::cout << "이동 후 s1: '" << s1 << "' (비어 있음)\n";
    std::cout << "이동 후 s2: " << s2 << "\n";

    return 0;
}
