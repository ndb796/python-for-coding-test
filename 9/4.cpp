#include <bits/stdc++.h>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[101][101];

int main(void) {
    cin >> n >> m;

    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, INF);
    }

    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
        }
    }

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < m; i++) {
        // A와 B가 서로에게 가는 비용은 1이라고 설정
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    // 거쳐 갈 노드 X와 최종 목적지 노드 K를 입력받기
    int x, k;
    cin >> x >> k;

    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    // 수행된 결과를 출력
    int distance = graph[1][k] + graph[k][x];

    // 도달할 수 없는 경우, -1을 출력
    if (distance >= INF) {
        cout << "-1" << '\n';
    }
    // 도달할 수 있다면, 최단 거리를 출력
    else {
        cout << distance << '\n';
    }
}