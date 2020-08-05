#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8][8]; // 초기 맵 배열
int temp[8][8]; // 벽을 설치한 뒤의 맵 배열

// 4가지 이동 방향에 대한 배열
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int result;

// 깊이 우선 탐색(DFS)을 이용해 각 바이러스가 사방으로 퍼지도록 하기
void virus(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 상, 하, 좌, 우 중에서 바이러스가 퍼질 수 있는 경우
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (temp[nx][ny] == 0) {
                // 해당 위치에 바이러스 배치하고, 다시 재귀적으로 수행
                temp[nx][ny] = 2;
                virus(nx, ny);
            }
        }
    }
}

// 현재 맵에서 안전 영역의 크기 계산하는 메서드
int getScore() {
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                score += 1;
            }
        }
    }
    return score;
}

// 깊이 우선 탐색(DFS)을 이용해 울타리를 설치하면서, 매 번 안전 영역의 크기 계산
void dfs(int count) {
    // 울타리가 3개 설치된 경우
    if (count == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = arr[i][j];
            }
        }
        // 각 바이러스의 위치에서 전파 진행
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 2) {
                    virus(i, j);
                }
            }
        }
        // 안전 영역의 최대값 계산
        result = max(result, getScore());
        return;
    }
    // 빈 공간에 울타리를 설치
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                count += 1;
                dfs(count);
                arr[i][j] = 0;
                count -= 1;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0);
    cout << result << '\n';
}