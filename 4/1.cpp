#include <bits/stdc++.h>

using namespace std;

// N을 입력받기
int n;
string plans;
int x = 1, y = 1;

// L, R, U, D에 따른 이동 방향 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main(void) {
    cin >> n;
    cin.ignore(); // 버퍼 비우기 
    getline(cin, plans);
    // 이동 계획을 하나씩 확인
    for (int i = 0; i < plans.size(); i++) {
        char plan = plans[i];
        // 이동 후 좌표 구하기 
        int nx = -1, ny = -1;
        for (int j = 0; j < 4; j++) {
            if (plan == moveTypes[j]) {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        // 공간을 벗어나는 경우 무시 
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        // 이동 수행 
        x = nx;
        y = ny;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}
