#include <iostream>
#include <vector>
#include <queue>

// BFS (너비 우선 탐색, Breadth-First Search)
// 시작 정점에서 가까운 정점부터 차례로 탐색
// 큐(Queue)를 사용하여 구현
// 시간 복잡도: O(V + E) | 최단 경로 탐색에 적합

// 인접 리스트로 표현한 그래프
class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adj;

public:
    explicit Graph(int v) : vertices(v), adj(v) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // 무방향 그래프
    }

    // BFS 탐색
    void bfs(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        std::cout << "BFS 탐색 순서 (시작: " << start << "): ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            // 방문하지 않은 이웃 정점을 큐에 추가
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }

    // BFS로 최단 경로 거리 계산
    std::vector<int> bfs_distance(int start) {
        std::vector<int> dist(vertices, -1);
        std::queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int neighbor : adj[v]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[v] + 1;
                    q.push(neighbor);
                }
            }
        }
        return dist;
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

    // BFS 탐색
    g.bfs(0);  // 0 1 3 2 4 5 (레벨 순서)

    // 최단 거리
    std::cout << "\nBFS 최단 거리 (시작: 0):\n";
    auto dist = g.bfs_distance(0);
    for (int i = 0; i < 6; i++) {
        std::cout << "  0 → " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
