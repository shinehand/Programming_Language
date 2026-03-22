#include <iostream>
#include "binary_tree.h"

int main() {
    BST<int> tree;

    // 삽입
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);

    /*
     * 트리 구조:
     *        5
     *       / \
     *      3   7
     *     / \ / \
     *    1  4 6  9
     */

    // 순회 출력
    tree.print_inorder();    // 1 3 4 5 6 7 9 (정렬된 순서)
    tree.print_preorder();   // 5 3 1 4 7 6 9
    tree.print_postorder();  // 1 4 3 6 9 7 5
    tree.print_levelorder(); // 5 3 7 1 4 6 9

    // 탐색
    std::cout << "search(4): " << (tree.search(4) ? "찾음" : "없음") << "\n";  // 찾음
    std::cout << "search(8): " << (tree.search(8) ? "찾음" : "없음") << "\n";  // 없음

    // 삭제
    tree.remove(3);  // 자식이 둘인 노드 삭제
    std::cout << "remove(3) 후 중위 순회: ";
    tree.print_inorder();  // 1 4 5 6 7 9

    tree.remove(7);  // 자식이 둘인 노드 삭제
    std::cout << "remove(7) 후 중위 순회: ";
    tree.print_inorder();  // 1 4 5 6 9

    return 0;
}
