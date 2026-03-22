#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <functional>

// 예외 처리 (Exception Handling)
// try/catch 블록으로 런타임 오류를 안전하게 처리

// === 기본 예외 처리 ===
void demonstrate_basic_exceptions() {
    std::cout << "=== 기본 예외 처리 ===\n";

    // 표준 예외들
    std::vector<int> v = {1, 2, 3};

    try {
        // std::out_of_range 예외 발생
        int val = v.at(10);
        std::cout << val;  // 실행되지 않음
    } catch (const std::out_of_range& e) {
        std::cout << "범위 오류: " << e.what() << "\n";
    }

    try {
        // std::invalid_argument 예외 발생
        int val = std::stoi("not_a_number");
        std::cout << val;
    } catch (const std::invalid_argument& e) {
        std::cout << "잘못된 인자: " << e.what() << "\n";
    }

    try {
        // std::overflow_error
        throw std::overflow_error("오버플로우 발생!");
    } catch (const std::overflow_error& e) {
        std::cout << "오버플로우: " << e.what() << "\n";
    }
}

// === 사용자 정의 예외 ===
// std::exception을 상속하여 커스텀 예외 클래스 만들기

class AppException : public std::exception {
protected:
    std::string message;

public:
    explicit AppException(const std::string& msg) : message(msg) {}

    // what() 재정의: 예외 메시지 반환
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ValidationError : public AppException {
private:
    std::string field;

public:
    ValidationError(const std::string& f, const std::string& msg)
        : AppException("검증 오류 [" + f + "]: " + msg), field(f) {}

    std::string get_field() const { return field; }
};

class DatabaseError : public AppException {
private:
    int error_code;

public:
    DatabaseError(int code, const std::string& msg)
        : AppException("DB 오류 [" + std::to_string(code) + "]: " + msg),
          error_code(code) {}

    int get_code() const { return error_code; }
};

void validate_age(int age) {
    if (age < 0) throw ValidationError("age", "나이는 0 이상이어야 합니다");
    if (age > 150) throw ValidationError("age", "나이가 너무 큽니다");
}

void connect_db(const std::string& host) {
    if (host.empty()) throw DatabaseError(1001, "호스트가 비어 있습니다");
    if (host == "invalid") throw DatabaseError(1002, "연결 실패");
}

void demonstrate_custom_exceptions() {
    std::cout << "\n=== 사용자 정의 예외 ===\n";

    // 나이 검증
    try {
        validate_age(-5);
    } catch (const ValidationError& e) {
        std::cout << e.what() << "\n";
        std::cout << "필드: " << e.get_field() << "\n";
    }

    // DB 연결 오류
    try {
        connect_db("invalid");
    } catch (const DatabaseError& e) {
        std::cout << e.what() << "\n";
        std::cout << "오류 코드: " << e.get_code() << "\n";
    }
}

// === 다중 catch ===
void demonstrate_multiple_catch() {
    std::cout << "\n=== 다중 catch ===\n";

    auto throw_random = [](int n) {
        switch (n % 3) {
            case 0: throw std::runtime_error("런타임 오류");
            case 1: throw ValidationError("name", "이름이 비어 있음");
            case 2: throw std::string("문자열 예외");
        }
    };

    for (int i = 0; i < 3; i++) {
        try {
            throw_random(i);
        } catch (const ValidationError& e) {
            // 더 구체적인 예외를 먼저 처리
            std::cout << "ValidationError: " << e.what() << "\n";
        } catch (const AppException& e) {
            std::cout << "AppException: " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cout << "std::exception: " << e.what() << "\n";
        } catch (...) {
            // 모든 예외 처리 (catch-all)
            std::cout << "알 수 없는 예외\n";
        }
    }
}

// === finally 패턴 (RAII로 구현) ===
class ScopeGuard {
private:
    std::function<void()> cleanup;

public:
    explicit ScopeGuard(std::function<void()> fn) : cleanup(fn) {}
    ~ScopeGuard() { cleanup(); }
};

void demonstrate_finally_pattern() {
    std::cout << "\n=== finally 패턴 (RAII) ===\n";

    {
        ScopeGuard guard([]() {
            std::cout << "정리 작업 실행 (finally와 동일)\n";
        });

        std::cout << "작업 실행 중...\n";
        // 예외가 발생해도 guard 소멸자가 호출됨
        std::cout << "작업 완료\n";
    }
    // 블록 종료 → guard 소멸 → cleanup 실행
}

int main() {
    demonstrate_basic_exceptions();
    demonstrate_custom_exceptions();
    demonstrate_multiple_catch();
    demonstrate_finally_pattern();

    return 0;
}
