#include <bits/stdc++.h>

using namespace std;

// 두 문자열을 입력 받기
string str1;
string str2; 

// 최소 편집 거리(Edit Distance) 계산을 위한 다이나믹 프로그래밍
int editDist(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));

    // DP 테이블 초기 설정
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    // 최소 편집 거리 계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 대입
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // 문자가 다르다면, 세 가지 경우 중에서 최솟값 찾기
            else { // 삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[n][m];
}

int main(void) {
    cin >> str1 >> str2;

    // 최소 편집 거리 출력
    cout << editDist(str1, str2) << '\n';
}