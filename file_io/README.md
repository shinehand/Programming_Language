# 파일 입출력 (File I/O)

## 헤더 및 클래스

```cpp
#include <fstream>

ifstream  // 읽기 전용
ofstream  // 쓰기 전용
fstream   // 읽기/쓰기
```

## 주요 모드

| 모드 | 설명 |
|---|---|
| `ios::in` | 읽기 모드 (기본) |
| `ios::out` | 쓰기 모드 (기본) |
| `ios::app` | 파일 끝에 추가 |
| `ios::binary` | 이진 모드 |
| `ios::trunc` | 기존 내용 삭제 후 쓰기 |

## 기본 패턴

```cpp
// 쓰기
ofstream out("file.txt");
out << "데이터\n";
out.close();

// 읽기
ifstream in("file.txt");
string line;
while (getline(in, line)) {
    cout << line << "\n";
}
```

## 컴파일 및 실행

```bash
g++ -std=c++17 file_io/file_io.cpp -o file_io && ./file_io
```
