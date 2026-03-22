#include <iostream>
#include "quad_tree.h"

int main() {
    // 100x100 공간의 쿼드트리 생성 (중심: 50,50)
    QuadTree qt(AABB(50, 50, 50, 50));

    qt.insert(Point(10, 10));
    qt.insert(Point(20, 80));
    qt.insert(Point(75, 30));
    qt.insert(Point(60, 70));
    qt.insert(Point(15, 45));
    qt.insert(Point(85, 85));
    qt.insert(Point(5,  5));
    qt.insert(Point(90, 10));

    std::cout << "Total points: " << qt.count() << "\n"; // 8

    // (0~30, 0~60) 범위 내 점 검색
    AABB search_range(15, 30, 15, 30);
    std::vector<Point> found;
    qt.query(search_range, found);

    std::cout << "Points in range [0~30, 0~60]:\n";
    for (const auto& p : found) {
        std::cout << "  (" << p.x << ", " << p.y << ")\n";
    }

    std::cout << "\nQuadTree structure:\n";
    qt.print();

    return 0;
}
