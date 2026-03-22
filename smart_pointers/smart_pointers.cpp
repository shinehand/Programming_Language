#include <iostream>
#include <memory>   // 스마트 포인터 헤더
#include <string>
#include <vector>

// 스마트 포인터 (Smart Pointers) - C++11
// 메모리 누수를 방지하는 자동 메모리 관리 도구
// RAII (Resource Acquisition Is Initialization) 패턴 적용

class Resource {
public:
    std::string name;

    Resource(const std::string& n) : name(n) {
        std::cout << "  Resource 생성: " << name << "\n";
    }

    ~Resource() {
        std::cout << "  Resource 소멸: " << name << "\n";
    }

    void use() const {
        std::cout << "  Resource 사용: " << name << "\n";
    }
};

// 1. unique_ptr - 유일한 소유권
// 하나의 unique_ptr만 리소스를 소유 가능
// 복사 불가, 이동(move)만 가능
void demonstrate_unique_ptr() {
    std::cout << "=== unique_ptr ===\n";

    // 생성
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("A");
    ptr1->use();

    // 이동 (소유권 이전)
    std::unique_ptr<Resource> ptr2 = std::move(ptr1);
    std::cout << "ptr1 (이동 후): " << (ptr1 ? "유효" : "nullptr") << "\n";
    std::cout << "ptr2 (이동 후): " << (ptr2 ? "유효" : "nullptr") << "\n";
    ptr2->use();

    // 배열 관리
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    std::cout << "arr[2] = " << arr[2] << "\n";

    std::cout << "unique_ptr 블록 종료 → 자동 해제:\n";
    // 블록 끝에서 자동으로 소멸자 호출 (메모리 자동 해제)
}

// 2. shared_ptr - 공유 소유권
// 여러 shared_ptr이 같은 리소스를 공유
// 참조 횟수(reference count)로 관리: 0이 되면 자동 소멸
void demonstrate_shared_ptr() {
    std::cout << "\n=== shared_ptr ===\n";

    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("B");
    std::cout << "참조 횟수: " << ptr1.use_count() << "\n";  // 1

    {
        std::shared_ptr<Resource> ptr2 = ptr1;  // 복사 → 참조 횟수 증가
        std::cout << "ptr2 생성 후 참조 횟수: " << ptr1.use_count() << "\n";  // 2
        ptr2->use();

        std::shared_ptr<Resource> ptr3 = ptr1;
        std::cout << "ptr3 생성 후 참조 횟수: " << ptr1.use_count() << "\n";  // 3

        std::cout << "블록 종료 → ptr2, ptr3 소멸 (아직 ptr1이 있으므로 Resource 유지)\n";
    }

    std::cout << "블록 후 참조 횟수: " << ptr1.use_count() << "\n";  // 1
    std::cout << "ptr1 소멸 시 Resource 해제:\n";
}

// 3. weak_ptr - 약한 참조 (순환 참조 방지)
// shared_ptr과 함께 사용, 참조 횟수에 포함되지 않음
struct Node {
    std::string name;
    std::shared_ptr<Node> next;  // 강한 참조
    std::weak_ptr<Node> prev;    // 약한 참조 (순환 참조 방지)

    Node(const std::string& n) : name(n) {
        std::cout << "  Node 생성: " << name << "\n";
    }
    ~Node() {
        std::cout << "  Node 소멸: " << name << "\n";
    }
};

void demonstrate_weak_ptr() {
    std::cout << "\n=== weak_ptr (순환 참조 방지) ===\n";

    auto node1 = std::make_shared<Node>("Node1");
    auto node2 = std::make_shared<Node>("Node2");

    node1->next = node2;   // node1 → node2 (강한 참조)
    node2->prev = node1;   // node2 → node1 (약한 참조, 순환 참조 방지)

    std::cout << "node1 참조 횟수: " << node1.use_count() << "\n";  // 1 (weak_ptr은 미포함)
    std::cout << "node2 참조 횟수: " << node2.use_count() << "\n";  // 2

    // weak_ptr 사용 (lock으로 shared_ptr 획득)
    if (auto locked = node2->prev.lock()) {
        std::cout << "node2->prev: " << locked->name << "\n";
    }

    std::cout << "블록 종료 → 메모리 정상 해제:\n";
}

void demonstrate_custom_deleter() {
    std::cout << "\n=== 커스텀 삭제자 ===\n";

    // 커스텀 삭제자 (파일, 소켓 등 리소스 관리에 유용)
    auto deleter = [](Resource* r) {
        std::cout << "  커스텀 삭제자 호출: ";
        delete r;
    };

    std::unique_ptr<Resource, decltype(deleter)> ptr(new Resource("C"), deleter);
    ptr->use();
    std::cout << "블록 종료 → 커스텀 삭제자 실행:\n";
}

int main() {
    demonstrate_unique_ptr();
    demonstrate_shared_ptr();
    demonstrate_weak_ptr();
    demonstrate_custom_deleter();

    return 0;
}
