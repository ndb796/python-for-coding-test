#include <bits/stdc++.h>

using namespace std;

class Virus {
public:
    int index;
    int second;
    int x;
    int y;
    Virus(int index, int second, int x, int y) {
        this->index = index;
        this->second = second;
        this->x = x;
        this->y = y;
    }
    // 정렬 기준은 '번호가 낮은 순서'
    bool operator <(Virus &other) {
        return this->index < other.index; 
    }
};

int n, k;
// 전체 보드 정보를 담는 배열
int graph[200][200];
// 바이러스에 대한 정보를 담는 리스트
vector<Virus> viruses;

// 바이러스가 퍼져나갈 수 있는 4가지의 위치
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    cin >> n >> k;

    // 보드 정보를 한 줄 단위로 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            // 해당 위치에 바이러스가 존재하는 경우
            if (graph[i][j] != 0) {
                // (바이러스 종류, 시간, 위치 X, 위치 Y) 삽입
                viruses.push_back(Virus(graph[i][j], 0, i, j));
            }
        }
    }

    // 정렬 이후에 큐로 옮기기 (낮은 번호의 바이러스가 먼저 증식하므로)
    sort(viruses.begin(), viruses.end());
    queue<Virus> q;
    for (int i = 0; i < viruses.size(); i++) {
        q.push(viruses[i]);
    }

    int target_s, target_x, target_y;
    cin >> target_s >> target_x >> target_y;
    
    // 너비 우선 탐색(BFS) 진행
    while (!q.empty()) {
        Virus virus = q.front();
        q.pop();
        // 정확히 second만큼 초가 지나거나, 큐가 빌 때까지 반복
        if (virus.second == target_s) break;
        // 현재 노드에서 주변 4가지 위치를 각각 확인
        for (int i = 0; i < 4; i++) {
            int nx = virus.x + dx[i];
            int ny = virus.y + dy[i];
            // 해당 위치로 이동할 수 있는 경우
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                // 아직 방문하지 않은 위치라면, 그 위치에 바이러스 넣기
                if (graph[nx][ny] == 0) {
                    graph[nx][ny] = virus.index;
                    q.push(Virus(virus.index, virus.second + 1, nx, ny));
                }
            }
        }
    }

    cout << graph[target_x - 1][target_y - 1] << '\n';
}