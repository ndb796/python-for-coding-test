#include <bits/stdc++.h>

using namespace std;

int n;
// 연산을 수행하고자 하는 수 리스트
vector<int> arr;
// 더하기, 빼기, 곱하기, 나누기 연산자 개수
int add, sub, mul, divi;

// 최솟값과 최댓값 초기화
int minValue = 1e9;
int maxValue = -1e9;

// 깊이 우선 탐색 (DFS) 메서드
void dfs(int i, int now) {
    // 모든 연산자를 다 사용한 경우, 최솟값과 최댓값 업데이트
    if (i == n) {
        minValue = min(minValue, now);
        maxValue = max(maxValue, now);
    }
    else {
        // 각 연산자에 대하여 재귀적으로 수행
        if (add > 0) {
            add -= 1;
            dfs(i + 1, now + arr[i]);
            add += 1;
        }
        if (sub > 0) {
            sub -= 1;
            dfs(i + 1, now - arr[i]);
            sub += 1;
        }
        if (mul > 0) {
            mul -= 1;
            dfs(i + 1, now * arr[i]);
            mul += 1;
        }
        if (divi > 0) {
            divi -= 1;
            dfs(i + 1, now / arr[i]);
            divi += 1;
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cin >> add >> sub >> mul >> divi;

    // DFS 메서드 호출
    dfs(1, arr[0]);

    // 최댓값과 최솟값 차례대로 출력
    cout << maxValue << '\n' << minValue << '\n';
}