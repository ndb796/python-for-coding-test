#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

int testCase, n;
int graph[125][125], d[125][125];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    cin >> testCase;

    // 전체 테스트 케이스(Test Case)만큼 반복
    for (int tc = 0; tc < testCase; tc++) {
        // 노드의 개수를 입력받기
        cin >> n;

        // 전체 맵 정보를 입력받기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        // 최단 거리 테이블을 모두 무한으로 초기화
        for (int i = 0; i < n; i++) {
            fill(d[i], d[i] + 125, INF);
        }

        int x = 0, y = 0; // 시작 위치는 (0, 0)
        // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({-graph[x][y], {0, 0}});
        d[x][y] = graph[x][y];

        // 다익스트라 알고리즘을 수행
        while (!pq.empty()) {
            // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
            int dist = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
            if (d[x][y] < dist) continue;
            // 현재 노드와 연결된 다른 인접한 노드들을 확인
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // 맵의 범위를 벗어나는 경우 무시
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int cost = dist + graph[nx][ny];
                // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                if (cost < d[nx][ny]) {
                    d[nx][ny] = cost;
                    pq.push({-cost, {nx, ny}});
                }
            }
        }
        cout << d[n - 1][n - 1] << '\n';
    }
}