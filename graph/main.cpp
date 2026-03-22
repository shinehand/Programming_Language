#include <iostream>
#include "graph.h"

int main() {
    // 예시 그래프:
    //   0 --- 1
    //   |   / |
    //   |  /  |
    //   2 --- 3
    //    \   /
    //      4

    std::cout << "=== 인접 행렬 표현 ===\n";
    GraphMatrix gm(5);
    gm.add_edge(0, 1);
    gm.add_edge(0, 2);
    gm.add_edge(1, 2);
    gm.add_edge(1, 3);
    gm.add_edge(2, 3);
    gm.add_edge(2, 4);
    gm.add_edge(3, 4);

    gm.print();

    std::cout << "0-1 간선 존재: " << gm.has_edge(0, 1) << "\n";  // 1
    std::cout << "0-3 간선 존재: " << gm.has_edge(0, 3) << "\n";  // 0

    std::cout << "\n=== 인접 리스트 표현 ===\n";
    GraphList gl(5);
    gl.add_edge(0, 1, 5);
    gl.add_edge(0, 2, 3);
    gl.add_edge(1, 2, 2);
    gl.add_edge(1, 3, 4);
    gl.add_edge(2, 3, 1);
    gl.add_edge(2, 4, 6);
    gl.add_edge(3, 4, 7);

    gl.print();

    std::cout << "\n정점 2의 이웃들:\n";
    for (const auto& [neighbor, weight] : gl.get_neighbors(2)) {
        std::cout << "  → " << neighbor << " (가중치: " << weight << ")\n";
    }

    return 0;
}
