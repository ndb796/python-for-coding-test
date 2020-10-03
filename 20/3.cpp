#include <bits/stdc++.h>

using namespace std;

int n = 5; // 데이터의 개수 N
int m = 5; // 찾고자 하는 부분합 M
int arr[] = {1, 2, 3, 2, 5}; // 전체 수열

int main() {
    int cnt = 0;
    int intervalSum = 0;
    int end = 0;

    // start를 차례대로 증가시키며 반복
    for (int start = 0; start < n; start++) {
        // end를 가능한 만큼 이동시키기
        while (intervalSum < m && end < n) {
            intervalSum += arr[end];
            end += 1;
        }
        // 부분합이 m일 때 카운트 증가
        if (intervalSum == m) {
            cnt += 1;
        }
        intervalSum -= arr[start];
    }

    cout << cnt << '\n';
}
