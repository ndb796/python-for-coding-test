#include <bits/stdc++.h>

using namespace std;

int n, m;
int result;

int main() {
    // N, M을 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m;

    // 한 줄씩 입력 받아 확인하기
    for (int i = 0; i < n; i++) {
        // 현재 줄에서 '가장 작은 수' 찾기
        int min_value = 10001;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            min_value = min(min_value, x);
        }
        // '가장 작은 수'들 중에서 가장 큰 수 찾기
        result = max(result, min_value);
    }

    cout << result << '\n'; // 최종 답안 출력
}