#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 순서를 뒤집어 '최장 증가 부분 수열' 문제로 변환
    reverse(v.begin(), v.end());

    // 다이나믹 프로그래밍을 위한 1차원 DP 테이블 초기화
    int dp[2000]; 
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // 가장 긴 증가하는 부분 수열(LIS) 알고리즘 수행
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // 열외해야 하는 병사의 최소 수를 출력
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    cout << n - maxValue << '\n';
}