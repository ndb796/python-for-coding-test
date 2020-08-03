#include <bits/stdc++.h>

using namespace std;

string inputData;

// 나이트가 이동할 수 있는 8가지 방향 정의
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void) {
    // 현재 나이트의 위치 입력받기
    cin >> inputData;
    int row = inputData[1] - '0';
    int column = inputData[0] - 'a';

    // 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
    int result = 0;
    for (int i = 0; i < 8; i++) {
        // 이동하고자 하는 위치 확인
        int nextRow = row + dx[i];
        int nextColumn = column + dy[i];
        // 해당 위치로 이동이 가능하다면 카운트 증가
        if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
            result += 1;
        }
    }

    cout << result << '\n';
    return 0;
}
