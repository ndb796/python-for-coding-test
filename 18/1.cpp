#include <bits/stdc++.h>

using namespace std;

// 여행지의 개수와 여행 계획에 속한 여행지의 개수
int n, m;
int parent[501]; // 부모 테이블 초기화

// 특정 원소가 속한 집합을 찾기
int findParent(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> n >> m;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Union 연산을 각각 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) { // 연결된 경우 합집합(Union) 연산 수행
                unionParent(i + 1, j + 1);
            }
        }
    }

    // 여행 계획 입력받기
    vector<int> plan;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        plan.push_back(x);
    }

    bool result = true;
    // 여행 계획에 속하는 모든 노드의 루트가 동일한지 확인
    for (int i = 0; i < m - 1; i++) {
        if (findParent(plan[i]) != findParent(plan[i + 1])) {
            result = false;
        }
    }

    // 여행 계획에 속하는 모든 노드가 서로 연결되어 있는지(루트가 동일한지) 확인
    if (result) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}