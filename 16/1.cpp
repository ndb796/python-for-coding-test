#include <bits/stdc++.h>

using namespace std;

int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(void) {
    // 테스트 케이스(Test Case) 입력
    cin >> testCase;
    for (int tc = 0; tc < testCase; tc++) {
        // 금광 정보 입력
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = arr[i][j];
            }
        }
        // 다이나믹 프로그래밍 진행
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int leftUp, leftDown, left;
                // 왼쪽 위에서 오는 경우
                if (i == 0) leftUp = 0;
                else leftUp = dp[i - 1][j - 1];
                // 왼쪽 아래에서 오는 경우
                if (i == n - 1) leftDown = 0;
                else leftDown = dp[i + 1][j - 1];
                // 왼쪽에서 오는 경우
                left = dp[i][j - 1];
                dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[i][m - 1]);
        }
        cout << result << '\n';
    }
}
