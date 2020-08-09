#include <bits/stdc++.h>

using namespace std;

int testCase, n, m;
// 모든 노드에 대한 진입차수는 0으로 초기화
int indegree[501];
// 각 노드에 연결된 간선 정보를 담기 위한 배열 초기화
bool graph[501][501];

int main(void) {
    cin >> testCase;

    // 테스트 케이스(Test Case)만큼 반복
    for (int tc = 0; tc < testCase; tc++) {
        fill(indegree, indegree + 501, 0);
        for (int i = 0; i < 501; i++) {
            fill(graph[i], graph[i] + 501, false);
        }

        cin >> n;
        // 작년 순위 정보 입력
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        // 방향 그래프의 간선 정보 초기화
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[v[i]][v[j]] = true;
                indegree[v[j]] += 1;
            }
        }

        // 올해 변경된 순위 정보 입력
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            // 간선의 방향 뒤집기
            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                indegree[a] += 1;
                indegree[b] -= 1;
            }
            else {
                graph[a][b] = true;
                graph[b][a] = false;
                indegree[a] -= 1;
                indegree[b] += 1;
            }
        }

        // 위상 정렬(Topology Sort) 시작
        vector<int> result; // 알고리즘 수행 결과를 담을 리스트
        queue<int> q; // 큐 라이브러리 사용

        // 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        bool certain = true; // 위상 정렬 결과가 오직 하나인지의 여부
        bool cycle = false; // 그래프 내 사이클이 존재하는지 여부

        // 정확히 노드의 개수만큼 반복
        for (int i = 0; i < n; i++) {
            // 큐가 비어 있다면 사이클이 발생했다는 의미
            if (q.size() == 0) {
                cycle = true;
                break;
            }
            // 큐의 원소가 2개 이상이라면 가능한 정렬 결과가 여러 개라는 의미
            if (q.size() >= 2) {
                certain = false;
                break;
            }
            // 큐에서 원소 꺼내기
            int now = q.front();
            q.pop();
            result.push_back(now);
            // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
            for (int j = 1; j <= n; j++) {
                if (graph[now][j]) {
                    indegree[j] -= 1;
                    // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
                    if (indegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }

        // 사이클이 발생하는 경우(일관성이 없는 경우)
        if (cycle) cout << "IMPOSSIBLE" << '\n';
        // 위상 정렬 결과가 여러 개인 경우
        else if (!certain) cout << "?" << '\n';
        // 위상 정렬을 수행한 결과 출력
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }
}