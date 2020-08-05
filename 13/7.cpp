#include <bits/stdc++.h>

using namespace std;

// 땅의 크기(N), L, R 값을 입력받기
int n, l, r;

// 전체 나라의 정보(N x N)를 입력받기
int graph[50][50];
int unions[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
void process(int x, int y, int index) {
    // (x, y)의 위치와 연결된 나라(연합) 정보를 담는 리스트
    vector<pair<int, int> > united;
    united.push_back({x, y});
    // 너비 우선 탐색 (BFS)을 위한 큐 라이브러리 사용
    queue<pair<int, int> > q;
    q.push({x, y});
    unions[x][y] = index; // 현재 연합의 번호 할당
    int summary = graph[x][y]; // 현재 연합의 전체 인구 수
    int count = 1; // 현재 연합의 국가 수
    // 큐가 빌 때까지 반복(BFS)
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 현재 위치에서 4가지 방향을 확인하며
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 바로 옆에 있는 나라를 확인하여
            if (0 <= nx && nx < n && 0 <= ny && ny < n && unions[nx][ny] == -1) {
                // 옆에 있는 나라와 인구 차이가 L명 이상, R명 이하라면
                int gap = abs(graph[nx][ny] - graph[x][y]);
                if (l <= gap && gap <= r) {
                    q.push({nx, ny});
                    // 연합에 추가하기
                    unions[nx][ny] = index;
                    summary += graph[nx][ny];
                    count += 1;
                    united.push_back({nx, ny});
                }
            }
        }
    }
    // 연합 국가끼리 인구를 분배
    for (int i = 0; i < united.size(); i++) {
        int x = united[i].first;
        int y = united[i].second;
        graph[x][y] = summary / count;
    }
}

int totalCount = 0;

int main(void) {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 더 이상 인구 이동을 할 수 없을 때까지 반복
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unions[i][j] = -1;
            }
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (unions[i][j] == -1) { // 해당 나라가 아직 처리되지 않았다면
                    process(i, j, index);
                    index += 1;
                }
            }
        }
        // 모든 인구 이동이 끝난 경우
        if (index == n * n) break;
        totalCount += 1;
    }

    // 인구 이동 횟수 출력
    cout << totalCount << '\n';
}