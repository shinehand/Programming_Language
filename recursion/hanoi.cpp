#include <iostream>

// 하노이 탑 (Tower of Hanoi)
// n개의 원판을 A에서 C로 옮기는 최소 이동 횟수: 2^n - 1
// 재귀의 대표적인 예시

int move_count = 0;  // 이동 횟수 카운터

// n개의 원판을 from에서 to로 (via를 경유하여) 이동
void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        // 기저 조건: 원판 1개는 바로 이동
        std::cout << "원판 " << n << ": " << from << " → " << to << "\n";
        move_count++;
        return;
    }

    // 1단계: 위의 n-1개를 via(보조 기둥)로 이동
    hanoi(n - 1, from, via, to);

    // 2단계: 가장 큰 원판을 to(목표 기둥)로 이동
    std::cout << "원판 " << n << ": " << from << " → " << to << "\n";
    move_count++;

    // 3단계: via에 있는 n-1개를 to(목표 기둥)로 이동
    hanoi(n - 1, via, to, from);
}

int main() {
    std::cout << "=== 하노이 탑 ===\n\n";

    // 3개 원판
    std::cout << "--- 원판 3개 (A → C) ---\n";
    move_count = 0;
    hanoi(3, 'A', 'C', 'B');
    std::cout << "총 이동 횟수: " << move_count << " (2^3 - 1 = 7)\n\n";

    // 4개 원판
    std::cout << "--- 원판 4개 (A → C) ---\n";
    move_count = 0;
    hanoi(4, 'A', 'C', 'B');
    std::cout << "총 이동 횟수: " << move_count << " (2^4 - 1 = 15)\n";

    return 0;
}
