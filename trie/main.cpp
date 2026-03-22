#include <iostream>
#include "trie.h"

int main() {
    Trie trie;

    // 단어 삽입
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bandana");

    // 단어 검색
    std::cout << "=== 단어 검색 ===\n";
    std::cout << "search(\"apple\"): " << trie.search("apple") << "\n";        // 1
    std::cout << "search(\"app\"): " << trie.search("app") << "\n";            // 1
    std::cout << "search(\"ap\"): " << trie.search("ap") << "\n";              // 0 (접두사만 존재)
    std::cout << "search(\"application\"): " << trie.search("application") << "\n";  // 1
    std::cout << "search(\"mango\"): " << trie.search("mango") << "\n";        // 0

    // 접두사 검색
    std::cout << "\n=== 접두사 검색 ===\n";
    std::cout << "starts_with(\"app\"): " << trie.starts_with("app") << "\n";   // 1
    std::cout << "starts_with(\"ban\"): " << trie.starts_with("ban") << "\n";   // 1
    std::cout << "starts_with(\"cat\"): " << trie.starts_with("cat") << "\n";   // 0

    // 접두사로 시작하는 모든 단어
    std::cout << "\n=== 접두사 \"app\"로 시작하는 단어들 ===\n";
    auto words = trie.find_all_with_prefix("app");
    for (const auto& w : words) {
        std::cout << "  " << w << "\n";
    }

    std::cout << "\n=== 접두사 \"ban\"으로 시작하는 단어들 ===\n";
    words = trie.find_all_with_prefix("ban");
    for (const auto& w : words) {
        std::cout << "  " << w << "\n";
    }

    // 삭제
    std::cout << "\n=== 삭제 테스트 ===\n";
    trie.remove("app");
    std::cout << "remove(\"app\") 후 search(\"app\"): " << trie.search("app") << "\n";      // 0
    std::cout << "remove(\"app\") 후 search(\"apple\"): " << trie.search("apple") << "\n";  // 1 (여전히 존재)

    return 0;
}
