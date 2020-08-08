#include <bits/stdc++.h>

using namespace std;

int n, k, l;
int arr[101][101]; // 맵 정보
vector<pair<int, char> > info; // 방향 회전 정보

// 처음에는 오른쪽을 보고 있으므로(동, 남, 서, 북)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int turn(int direction, char c) {
    if (c == 'L') direction = (direction == 0)? 3 : direction - 1;
    else direction = (direction + 1) % 4;
    return direction;
}

int simulate() {
    int x = 1, y = 1; // 뱀의 머리 위치
    arr[x][y] = 2; // 뱀이 존재하는 위치는 2로 표시
    int direction = 0; // 처음에는 동쪽을 보고 있음
    int time = 0; // 시작한 뒤에 지난 '초' 시간
    int index = 0; // 다음에 회전할 정보
    queue<pair<int, int> > q; // 뱀이 차지하고 있는 위치 정보(꼬리가 앞쪽)
    q.push({x, y});

    while (true) {
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        // 맵 범위 안에 있고, 뱀의 몸통이 없는 위치라면
        if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] != 2) {
            // 사과가 없다면 이동 후에 꼬리 제거
            if (arr[nx][ny] == 0) {
                arr[nx][ny] = 2;
                q.push({nx, ny});
                int px = q.front().first;
                int py = q.front().second;
                q.pop();
                arr[px][py] = 0;
            }
            // 사과가 있다면 이동 후에 꼬리 그대로 두기
            if (arr[nx][ny] == 1) {
                arr[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        // 벽이나 뱀의 몸통과 부딪혔다면
        else {
            time += 1;
            break;
        }
        // 다음 위치로 머리를 이동
        x = nx;
        y = ny;
        time += 1;
        if (index < l && time == info[index].first) { // 회전할 시간인 경우 회전
            direction = turn(direction, info[index].second);
            index += 1;
        }
    }
    return time;
}

int main(void) {
    cin >> n >> k;

    // 맵 정보(사과 있는 곳은 1로 표시)
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    // 방향 회전 정보 입력
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        info.push_back({x, c});
    }

    cout << simulate() << '\n';
}