#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// LCS (Longest Common Subsequence) - 최장 공통 부분 수열
// 두 문자열에서 순서를 유지하며 공통으로 등장하는 가장 긴 부분 수열

// LCS 길이 계산 (DP 테이블)
int lcs_length(const std::string& s1, const std::string& s2) {
    int m = s1.size(), n = s2.size();
    // dp[i][j] = s1[0..i-1]과 s2[0..j-1]의 LCS 길이
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;  // 문자가 같으면 +1
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);  // 더 큰 값 선택
            }
        }
    }
    return dp[m][n];
}

// LCS 문자열 자체를 역추적으로 복원
std::string lcs_string(const std::string& s1, const std::string& s2) {
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // 역추적 (Backtracking)
    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result += s1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// DP 테이블 출력
void print_dp_table(const std::string& s1, const std::string& s2) {
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s1[i-1] == s2[j-1]) ? dp[i-1][j-1] + 1
                                              : std::max(dp[i-1][j], dp[i][j-1]);

    std::cout << "DP 테이블:\n    ";
    for (char c : s2) std::cout << c << " ";
    std::cout << "\n";
    for (int i = 0; i <= m; i++) {
        if (i > 0) std::cout << s1[i-1] << " ";
        else std::cout << "  ";
        for (int j = 0; j <= n; j++) std::cout << dp[i][j] << " ";
        std::cout << "\n";
    }
}

int main() {
    std::cout << "=== 최장 공통 부분 수열 (LCS) ===\n\n";

    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCAB";

    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n\n";

    print_dp_table(s1, s2);

    std::cout << "\nLCS 길이: " << lcs_length(s1, s2) << "\n";  // 4
    std::cout << "LCS 문자열: " << lcs_string(s1, s2) << "\n";  // BCAB 또는 BDAB

    // 추가 예시
    std::cout << "\n추가 예시:\n";
    std::string a = "AGGTAB", b = "GXTXAYB";
    std::cout << "\"" << a << "\" vs \"" << b << "\"\n";
    std::cout << "LCS 길이: " << lcs_length(a, b) << "\n";  // 4
    std::cout << "LCS 문자열: " << lcs_string(a, b) << "\n";  // GTAB

    return 0;
}
