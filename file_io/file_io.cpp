#include <iostream>
#include <fstream>    // 파일 입출력
#include <sstream>   // 문자열 스트림
#include <string>
#include <vector>
#include <stdexcept>

// 파일 입출력 (File I/O)
// fstream, ifstream, ofstream 사용

const std::string TEST_FILE = "/tmp/test_output.txt";
const std::string CSV_FILE = "/tmp/students.csv";

void demonstrate_write() {
    std::cout << "=== 파일 쓰기 (ofstream) ===\n";

    // ofstream: 쓰기 전용 파일 스트림
    std::ofstream outFile(TEST_FILE);

    if (!outFile.is_open()) {
        throw std::runtime_error("파일을 열 수 없습니다: " + TEST_FILE);
    }

    outFile << "안녕하세요, 파일 입출력!\n";
    outFile << "C++ fstream 예제\n";
    outFile << "숫자: " << 42 << "\n";
    outFile << "실수: " << 3.14 << "\n";

    outFile.close();  // 파일 닫기 (소멸자에서 자동 호출됨)
    std::cout << "파일 쓰기 완료: " << TEST_FILE << "\n";
}

void demonstrate_read() {
    std::cout << "\n=== 파일 읽기 (ifstream) ===\n";

    // ifstream: 읽기 전용 파일 스트림
    std::ifstream inFile(TEST_FILE);

    if (!inFile.is_open()) {
        throw std::runtime_error("파일을 열 수 없습니다: " + TEST_FILE);
    }

    // 줄 단위 읽기
    std::string line;
    int lineNum = 1;
    while (std::getline(inFile, line)) {
        std::cout << lineNum++ << ": " << line << "\n";
    }

    inFile.close();
}

void demonstrate_append() {
    std::cout << "\n=== 파일 추가 (ios::app) ===\n";

    // ios::app: 파일 끝에 추가 모드
    std::ofstream outFile(TEST_FILE, std::ios::app);
    outFile << "추가된 줄 1\n";
    outFile << "추가된 줄 2\n";
    outFile.close();

    std::cout << "추가 완료. 전체 내용:\n";

    std::ifstream inFile(TEST_FILE);
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << "  " << line << "\n";
    }
}

void demonstrate_csv() {
    std::cout << "\n=== CSV 파일 처리 ===\n";

    // CSV 쓰기
    {
        std::ofstream csv(CSV_FILE);
        csv << "이름,나이,점수\n";
        csv << "Alice,20,95\n";
        csv << "Bob,22,87\n";
        csv << "Charlie,21,92\n";
        csv << "Dave,23,78\n";
    }

    // CSV 읽기 (파싱)
    std::ifstream csv(CSV_FILE);
    std::string line;

    // 헤더 건너뛰기
    std::getline(csv, line);
    std::cout << "헤더: " << line << "\n\n";

    struct Student { std::string name; int age; int score; };
    std::vector<Student> students;

    while (std::getline(csv, line)) {
        std::stringstream ss(line);
        std::string token;
        Student s;

        std::getline(ss, s.name, ',');
        std::getline(ss, token, ','); s.age = std::stoi(token);
        std::getline(ss, token, ','); s.score = std::stoi(token);
        students.push_back(s);
    }

    std::cout << "파싱된 학생 데이터:\n";
    for (const auto& s : students) {
        std::cout << "  " << s.name << " (나이: " << s.age << ", 점수: " << s.score << ")\n";
    }
}

void demonstrate_binary_io() {
    std::cout << "\n=== 이진 파일 입출력 ===\n";

    const std::string BIN_FILE = "/tmp/test_binary.bin";

    // 이진 쓰기
    {
        std::ofstream bin(BIN_FILE, std::ios::binary);
        int arr[] = {1, 2, 3, 4, 5};
        bin.write(reinterpret_cast<const char*>(arr), sizeof(arr));
        std::cout << "이진 파일 쓰기 완료\n";
    }

    // 이진 읽기
    {
        std::ifstream bin(BIN_FILE, std::ios::binary);
        int arr[5];
        bin.read(reinterpret_cast<char*>(arr), sizeof(arr));

        std::cout << "이진 파일 읽기: ";
        for (int x : arr) std::cout << x << " ";
        std::cout << "\n";
    }
}

int main() {
    try {
        demonstrate_write();
        demonstrate_read();
        demonstrate_append();
        demonstrate_csv();
        demonstrate_binary_io();
    } catch (const std::exception& e) {
        std::cerr << "오류: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
