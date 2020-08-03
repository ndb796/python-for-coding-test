#include <bits/stdc++.h>
#define INF 999999999 // 무한의 비용 선언

using namespace std;

// 2차원 리스트를 이용해 인접 행렬 표현
int graph[3][3] = {
    {0, 7, 5},
    {7, 0, INF},
    {5, INF, 0}
};

int main(void) {
    // 그래프 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}