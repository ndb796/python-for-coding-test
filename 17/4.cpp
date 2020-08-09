#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
int n, m;
// 시작 노드를 1번 헛간으로 설정
int start = 1;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만들기
vector<pair<int, int> > graph[20001];
// 최단 거리 테이블 만들기
int d[20001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보를 꺼내기
        int dist = -pq.top().first; // 현재 노드까지의 비용 
        int now = pq.top().second; // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // a번 노드와 b번 노드의 이동 비용이 1이라는 의미(양방향)
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 20001, INF);

    // 다익스트라 알고리즘을 수행
    dijkstra(start);

    // 가장 최단 거리가 먼 노드 번호(동빈이가 숨을 헛간의 번호)
    int maxNode = 0;
    // 도달할 수 있는 노드 중에서, 가장 최단 거리가 먼 노드와의 최단 거리
    int maxDistance = 0;
    // 가장 최단 거리가 먼 노드와의 최단 거리와 동일한 최단 거리를 가지는 노드들의 리스트
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (maxDistance < d[i]) {
            maxNode = i;
            maxDistance = d[i];
            result.clear();
            result.push_back(maxNode);
        }
        else if (maxDistance == d[i]) {
            result.push_back(i);
        }
    }

    cout << maxNode << ' ' << maxDistance << ' ' << result.size() << '\n';
}