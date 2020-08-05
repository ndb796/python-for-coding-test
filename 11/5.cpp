#include <bits/stdc++.h>

using namespace std;

int n, m;
// 1부터 10까지의 무게를 담을 수 있는 배열
int arr[11];

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x] += 1;
    }

    int result = 0;

    // 1부터 m까지의 각 무게에 대하여 처리
    for (int i = 1; i <= m; i++) {
        n -= arr[i]; // 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수) 제외
        result += arr[i] * n; // B가 선택하는 경우의 수와 곱해주기
    }

    cout << result << '\n';
}