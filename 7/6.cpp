#include <bits/stdc++.h>

using namespace std;

// N(가게의 부품 개수)와 M(손님이 확인 요청한 부품 개수)
int n, m;
int arr[1000001];
vector<int> targets;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }
    // 손님이 확인 요청한 부품 번호를 하나씩 확인
    for (int i = 0; i < m; i++) {
        // 해당 부품이 존재하는지 확인
        if (arr[targets[i]] == 1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}