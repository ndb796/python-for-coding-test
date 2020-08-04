#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a, b;

bool compare(int x, int y) {
    return x > y;
}

int main(void) {
    // N과 K를 입력받기
    cin >> n >> k;
    // 배열 A의 모든 원소를 입력받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    // 배열 B의 모든 원소를 입력받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    // 배열 A는 오름차순 정렬 수행
    sort(a.begin(), a.end());
    // 배열 B는 내림차순 정렬 수행
    sort(b.begin(), b.end(), compare);

    // 첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 K번 비교 
    for (int i = 0; i < k; i++) {
        // A의 원소가 B의 원소보다 작은 경우
        if (a[i] < b[i]) swap(a[i], b[i]); // 두 원소를 교체
        // A의 원소가 B의 원소보다 크거나 같을 때, 반복문을 탈출
        else break;
    }

    // 배열 A의 모든 원소의 합을 출력
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    cout << result << '\n';
}
