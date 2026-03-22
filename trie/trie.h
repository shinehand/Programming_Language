#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 트라이 (Trie) - 문자열 탐색 트리
// 각 노드가 하나의 문자를 나타내며, 루트에서 리프까지의 경로가 단어를 구성
class Trie {
private:
    struct Node {
        std::unordered_map<char, Node*> children;
        bool is_end;  // 이 노드에서 단어가 끝나는지 여부

        Node() : is_end(false) {}

        ~Node() {
            for (auto& [ch, child] : children) {
                delete child;
            }
        }
    };

    Node* root;

public:
    Trie() : root(new Node()) {}
    ~Trie() { delete root; }

    // 단어 삽입 O(m) - m: 단어 길이
    void insert(const std::string& word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->is_end = true;  // 단어의 끝 표시
    }

    // 단어 검색 (완전 일치) O(m)
    bool search(const std::string& word) const {
        Node* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return cur->is_end;
    }

    // 접두사 검색 (prefix가 존재하는지) O(m)
    bool starts_with(const std::string& prefix) const {
        Node* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return true;
    }

    // 단어 삭제
    bool remove(const std::string& word) {
        return remove(root, word, 0);
    }

    // 접두사로 시작하는 모든 단어 찾기
    std::vector<std::string> find_all_with_prefix(const std::string& prefix) const {
        std::vector<std::string> result;
        Node* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) return result;
            cur = cur->children[c];
        }
        dfs(cur, prefix, result);
        return result;
    }

private:
    bool remove(Node* node, const std::string& word, int depth) {
        if (depth == (int)word.size()) {
            if (!node->is_end) return false;
            node->is_end = false;
            return node->children.empty();  // 자식 없으면 노드 삭제 가능
        }
        char c = word[depth];
        if (node->children.find(c) == node->children.end()) return false;

        bool should_delete = remove(node->children[c], word, depth + 1);
        if (should_delete) {
            delete node->children[c];
            node->children.erase(c);
            return !node->is_end && node->children.empty();
        }
        return false;
    }

    void dfs(Node* node, const std::string& current, std::vector<std::string>& result) const {
        if (node->is_end) result.push_back(current);
        for (const auto& [ch, child] : node->children) {
            dfs(child, current + ch, result);
        }
    }
};
