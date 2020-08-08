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

    sort(v.begin(), v.end());

    // 중간값(median)을 출력
    cout << v[(n - 1) / 2] << '\n';
}