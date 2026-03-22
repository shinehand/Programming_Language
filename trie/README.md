# 트라이 (Trie)

## 개념

트라이(Trie)는 문자열을 효율적으로 저장하고 검색하는 **트리 자료구조**입니다. 각 노드가 하나의 문자를 나타내며, 루트에서 특정 노드까지의 경로가 문자열의 접두사를 형성합니다.

### 구조

```
         root
        /    \
       a      b
       |      |
       p      a
       |     / \
       p    n   n
      /|\   |   |
     l i y  a   a
     |     |   |
     e     n   n
           |   |
           a   a
```

`apple`, `app`, `apply` → 공통 접두사 `app` 공유

## 주요 연산

| 메서드 | 설명 | 시간 복잡도 |
|---|---|---|
| `insert(word)` | 단어 삽입 | O(m) |
| `search(word)` | 단어 검색 | O(m) |
| `starts_with(prefix)` | 접두사 존재 여부 | O(m) |
| `remove(word)` | 단어 삭제 | O(m) |
| `find_all_with_prefix(p)` | 접두사로 시작하는 단어들 | O(m + k) |

> m: 문자열 길이, k: 결과 단어 수

## 활용 분야

- 자동완성 (Auto-complete)
- 맞춤법 검사
- IP 라우팅
- 사전 검색

## 컴파일 및 실행

```bash
g++ -std=c++17 trie/main.cpp -o trie && ./trie
```
