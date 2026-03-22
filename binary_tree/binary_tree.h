#pragma once
#include <iostream>
#include <queue>
#include <stdexcept>

// 이진 탐색 트리 (Binary Search Tree)
// 왼쪽 서브트리 < 루트 < 오른쪽 서브트리
template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // 재귀 삽입 헬퍼
    Node* insert(Node* node, const T& val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        // 중복은 무시
        return node;
    }

    // 재귀 탐색 헬퍼
    Node* search(Node* node, const T& val) const {
        if (!node || node->data == val) return node;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    // 서브트리에서 최솟값 노드 반환
    Node* find_min(Node* node) const {
        while (node->left) node = node->left;
        return node;
    }

    // 재귀 삭제 헬퍼
    Node* remove(Node* node, const T& val) {
        if (!node) return nullptr;
        if (val < node->data) {
            node->left = remove(node->left, val);
        } else if (val > node->data) {
            node->right = remove(node->right, val);
        } else {
            // 삭제할 노드 발견
            if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            } else if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            // 자식이 둘인 경우: 오른쪽 서브트리의 최솟값으로 대체
            Node* successor = find_min(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
        return node;
    }

    // 전위 순회 (Pre-order): 루트 → 왼쪽 → 오른쪽
    void preorder(Node* node) const {
        if (!node) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // 중위 순회 (In-order): 왼쪽 → 루트 → 오른쪽 (정렬된 순서)
    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // 후위 순회 (Post-order): 왼쪽 → 오른쪽 → 루트
    void postorder(Node* node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    // 트리 메모리 해제
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    // 값 삽입
    void insert(const T& val) {
        root = insert(root, val);
    }

    // 값 탐색 (존재 여부 반환)
    bool search(const T& val) const {
        return search(root, val) != nullptr;
    }

    // 값 삭제
    void remove(const T& val) {
        root = remove(root, val);
    }

    // 전위 순회 출력
    void print_preorder() const {
        std::cout << "전위 순회: ";
        preorder(root);
        std::cout << "\n";
    }

    // 중위 순회 출력 (정렬된 순서)
    void print_inorder() const {
        std::cout << "중위 순회: ";
        inorder(root);
        std::cout << "\n";
    }

    // 후위 순회 출력
    void print_postorder() const {
        std::cout << "후위 순회: ";
        postorder(root);
        std::cout << "\n";
    }

    // 레벨 순서 순회 (BFS)
    void print_levelorder() const {
        if (!root) return;
        std::cout << "레벨 순서: ";
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            std::cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        std::cout << "\n";
    }

    bool empty() const { return root == nullptr; }
};
