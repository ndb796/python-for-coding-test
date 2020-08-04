#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    // N을 입력받기
    cin >> n;

    // N개의 정수를 입력받아 리스트에 저장
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 기본 정렬 라이브러리를 이용하여 정렬 수행
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}
