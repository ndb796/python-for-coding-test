#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;
int parent[MAX]; // 부모에 대한 정보
int d[MAX]; // 각 노드까지의 깊이(depth)
int c[MAX]; // 각 노드의 깊이가 계산되었는지 여부
vector<int> graph[MAX]; // 그래프(graph) 정보

// 루트 노드부터 시작하여 깊이(depth)를 구하는 함수
void dfs(int x, int depth) {
    c[x] = true;
    d[x] = depth;
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (c[y]) continue; // 이미 깊이를 구했다면 넘기기
        parent[y] = x;
        dfs(y, depth + 1);
    }
}

// A와 B의 최소 공통 조상을 찾는 함수
int lca(int a, int b) {
    // 먼저 깊이(depth)가 동일하도록
    while (d[a] != d[b]) {
        if (d[a] > d[b]) {
            a = parent[a];
        }
        else b = parent[b];
    }
    // 노드가 같아지도록
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0); // 루트 노드는 1번 노드

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
