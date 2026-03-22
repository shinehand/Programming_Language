#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// 그래프 - 인접 행렬 표현 (Adjacency Matrix)
// 메모리: O(V²), 간선 확인: O(1)
class GraphMatrix {
private:
    int vertices;                     // 정점 수
    std::vector<std::vector<int>> adj;  // 인접 행렬

public:
    explicit GraphMatrix(int v) : vertices(v), adj(v, std::vector<int>(v, 0)) {}

    // 간선 추가 (무방향 그래프)
    void add_edge(int u, int v, int weight = 1) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
            throw std::out_of_range("Vertex index out of range");
        adj[u][v] = weight;
        adj[v][u] = weight;  // 무방향이므로 양쪽 설정
    }

    // 간선 제거
    void remove_edge(int u, int v) {
        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    // 간선 존재 여부
    bool has_edge(int u, int v) const {
        return adj[u][v] != 0;
    }

    // 인접 행렬 출력
    void print() const {
        std::cout << "인접 행렬:\n   ";
        for (int i = 0; i < vertices; i++) std::cout << i << " ";
        std::cout << "\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                std::cout << adj[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    int get_vertices() const { return vertices; }
    const std::vector<std::vector<int>>& get_adj() const { return adj; }
};

// 그래프 - 인접 리스트 표현 (Adjacency List)
// 메모리: O(V+E), 이웃 순회: O(degree)
class GraphList {
private:
    int vertices;
    std::vector<std::list<std::pair<int,int>>> adj;  // {이웃 정점, 가중치}

public:
    explicit GraphList(int v) : vertices(v), adj(v) {}

    // 간선 추가 (무방향 그래프)
    void add_edge(int u, int v, int weight = 1) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
            throw std::out_of_range("Vertex index out of range");
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    // 간선 제거
    void remove_edge(int u, int v) {
        adj[u].remove_if([v](const std::pair<int,int>& p) { return p.first == v; });
        adj[v].remove_if([u](const std::pair<int,int>& p) { return p.first == u; });
    }

    // 인접 리스트 출력
    void print() const {
        std::cout << "인접 리스트:\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << i << ": ";
            for (const auto& [neighbor, weight] : adj[i]) {
                std::cout << neighbor << "(w=" << weight << ") -> ";
            }
            std::cout << "NULL\n";
        }
    }

    int get_vertices() const { return vertices; }
    const std::list<std::pair<int,int>>& get_neighbors(int v) const { return adj[v]; }
};
