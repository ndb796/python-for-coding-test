#include <bits/stdc++.h>

using namespace std;

// 노드의 개수와 간선의 개수
int n, m;
int parent[200001]; // 부모 테이블 초기화
// 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
vector<pair<int, pair<int, int> > > edges;
int result;

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

    // 모든 간선에 대한 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
        edges.push_back({z, {x, y}});
    }

    // 간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());
    int total = 0; // 전체 가로등 비용

    // 간선을 하나씩 확인하며
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        total += cost;
        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << total - result << '\n';
}