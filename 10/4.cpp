#include <bits/stdc++.h>

using namespace std;

// 노드의 개수(V)와 간선(Union 연산)의 개수(E)
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
int parent[100001]; // 부모 테이블 초기화하기

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
    cin >> v >> e;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    bool cycle = false; // 사이클 발생 여부

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        // 사이클이 발생한 경우 종료
        if (findParent(a) == findParent(b)) {
            cycle = true;
            break;
        }
        // 사이클이 발생하지 않았다면 합집합(Union) 연산 수행
        else {
            unionParent(a, b);
        }
    }

    if (cycle) {
        cout << "사이클이 발생했습니다." << '\n';
    }
    else {
        cout << "사이클이 발생하지 않았습니다." << '\n';
    }
}