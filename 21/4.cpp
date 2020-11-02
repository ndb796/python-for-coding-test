#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
// 노드의 개수는 최대 500개라고 가정
int n, m;
// 모든 간선에 대한 정보를 담는 리스트 만들기
vector<pair<int, pair<int, int> > > edges;
// 최단 거리 테이블 만들기
long long d[501]; // 오버 플로우 및 언더 플로우 방지

bool bf(int start) {
    // 시작 노드에 대해서 초기화
    d[start] = 0;
    // 전체 n - 1번의 라운드(round)를 반복
    for (int i = 0; i < n; i++) {
        // 매 반복마다 "모든 간선"을 확인하며
        for (int j = 0; j < m; j++) {
            int cur_node = edges[j].first;
            int next_node = edges[j].second.first;
            int edge_cost = edges[j].second.second;
            // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (d[cur_node] != INF and d[next_node] > d[cur_node] + edge_cost) {
                d[next_node] = d[cur_node] + edge_cost;
                // n번째 라운드에서도 값이 갱신된다면 음수 순환이 존재
                if (i == n - 1) return true;
            }
        }
    }
    return false;
}

int main(void) {
    cin >> n >> m;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        edges.push_back({a, {b, c}});
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 501, INF);
    
    // 벨만 포드 알고리즘을 수행
    bool negative_cycle = bf(1); // 1번 노드가 시작 노드

    if (negative_cycle) {
        cout << "-1" << '\n';
        return 0;
    }
    // 1번 노드를 제외한 다른 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 2; i <= n; i++) {
        // 도달할 수 없는 경우, -1을 출력
        if (d[i] == INF) {
            cout << "-1" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
}
