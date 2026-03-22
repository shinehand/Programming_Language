#include <iostream>
#include <vector>
#include <stack>

// DFS (깊이 우선 탐색, Depth-First Search)
// 한 방향으로 최대한 깊이 탐색 후 백트래킹
// 재귀 또는 스택(Stack)을 사용하여 구현
// 시간 복잡도: O(V + E) | 경로 탐색, 사이클 감지에 적합

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adj;

    // 재귀 DFS 헬퍼
    void dfs_recursive(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs_recursive(neighbor, visited);
            }
        }
    }

public:
    explicit Graph(int v) : vertices(v), adj(v) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 재귀 방식 DFS
    void dfs_recursive(int start) {
        std::vector<bool> visited(vertices, false);
        std::cout << "DFS 재귀 (시작: " << start << "): ";
        dfs_recursive(start, visited);
        std::cout << "\n";
    }

    // 반복 방식 DFS (스택 사용)
    void dfs_iterative(int start) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> st;

        st.push(start);

        std::cout << "DFS 반복 (시작: " << start << "): ";

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                visited[v] = true;
                std::cout << v << " ";

                // 역순으로 추가 (재귀 방식과 동일한 순서 유지)
                for (int i = adj[v].size() - 1; i >= 0; i--) {
                    if (!visited[adj[v][i]]) {
                        st.push(adj[v][i]);
                    }
                }
            }
        }
        std::cout << "\n";
    }

    // DFS로 연결 요소 개수 찾기
    int count_components() {
        std::vector<bool> visited(vertices, false);
        int components = 0;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs_recursive(i, visited);
                components++;
            }
        }
        return components;
    }

    void print_graph() const {
        std::cout << "그래프 인접 리스트:\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << i << ": ";
            for (int v : adj[i]) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    //  그래프 구조:
    //  0 - 1 - 2
    //  |   |
    //  3 - 4 - 5
    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    g.print_graph();
    std::cout << "\n";

    g.dfs_recursive(0);  // 0 1 2 4 3 5
    g.dfs_iterative(0);  // 0 1 2 4 3 5

    // 연결 요소 개수
    std::cout << "\n=== 비연결 그래프 ===\n";
    Graph g2(7);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(3, 4);
    g2.add_edge(5, 6);

    std::cout << "연결 요소 개수: ";
    int comps = g2.count_components();
    std::cout << "\n총 " << comps << "개의 연결 요소\n";

    return 0;
}
