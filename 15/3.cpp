#include <bits/stdc++.h>

using namespace std;

// 집의 개수(N)와 공유기의 개수(C)
int n, c;
vector<int> arr;

int main() {
    cin >> n >> c;

    // 전체 집의 좌표 정보를 입력 받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행을 위해 정렬 수행
    sort(arr.begin(), arr.end());

    int start = arr[1] - arr[0]; // 집의 좌표 중에 가장 작은 값
    int end = arr[n - 1] - arr[0]; // 집의 좌표 값 중에서 가장 큰 값
    int result = 0;

    while (start <= end) {
        // mid는 가장 인접한 두 공유기 사이의 거리(Gap)을 의미
        int mid = (start + end) / 2;
        int value = arr[0];
        int cnt = 1;
        // 현재의 mid 값을 이용해 공유기를 설치하기
        for (int i = 1; i < n; i++) { // 앞에서부터 차근차근 설치
            if (arr[i] >= value + mid) {
                value = arr[i];
                cnt += 1;
            }
        }
        // C개 이상의 공유기를 설치할 수 있는 경우, 거리를 증가시키기
        if (cnt >= c) {
            start = mid + 1;
            result = mid; // 최적의 결과를 저장
        }
        // C개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소시키기
        else {
            end = mid - 1;
        }
    }

    cout << result << '\n';
}