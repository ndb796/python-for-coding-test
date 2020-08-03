#include <bits/stdc++.h>

using namespace std;

// 행(Row)이 3개인 인접 리스트 표현
vector<pair<int, int> > graph[3];

int main(void) {
    // 노드 0에 연결된 노드 정보 저장 {노드, 거리}
    graph[0].push_back({1, 7});
    graph[0].push_back({2, 5});

    // 노드 1에 연결된 노드 정보 저장 {노드, 거리}
    graph[1].push_back({0, 7});

    // 노드 2에 연결된 노드 정보 저장 {노드, 거리}
    graph[2].push_back({0, 5});

    // 그래프 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << '(' << graph[i][j].first << ',' << graph[i][j].second << ')' << ' ';
        }
        cout << '\n';
    } 
}