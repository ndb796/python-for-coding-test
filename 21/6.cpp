#include <bits/stdc++.h>
#define MAX 100001
#define LOG 21 // 2^20 = 1,000,000

using namespace std;

int n, m;
int parent[MAX][LOG]; // 부모에 대한 정보
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
        parent[y][0] = x;
        dfs(y, depth + 1);
    }
}

// 전체 부모 관계를 설정하는 함수
void setParent() {
    dfs(1, 0); // 루트 노드는 1번 노드
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

// A와 B의 최소 공통 조상을 찾는 함수
int lca(int a, int b) {
    // y가 더 깊도록 설정
    if(d[a] > d[b]) {
        swap(a, b);
    }
    // 먼저 깊이(depth)가 동일하도록
    for(int i = LOG - 1; i >= 0; i--) {
        if(d[b] - d[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }
    // 부모가 같아지도록 
    if(a == b) return a;
    for(int i = LOG - 1; i >= 0; i--) {
        // 조상을 향해 거슬러 올라가기
        if(parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    // 이후에 부모가 찾고자 하는 조상
    return parent[a][0];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    setParent();

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
}
