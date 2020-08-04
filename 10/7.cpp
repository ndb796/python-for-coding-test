#include <bits/stdc++.h>

using namespace std;

// 노드의 개수(N)와 연산의 개수(M)
int n, m;
int parent[100001]; // 부모 테이블 초기화

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

    // 각 연산을 하나씩 확인 
    for (int i = 0; i < m; i++) {
        int oper, a, b;
        cin >> oper >> a >> b;
        // 합집합(Union) 연산인 경우
        if (oper == 0) {
            unionParent(a, b);
        }
        // 찾기(Find) 연산인 경우
        else if (oper == 1) {
            if (findParent(a) == findParent(b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
}