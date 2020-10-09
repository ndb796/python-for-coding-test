#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int pos1X;
    int pos1Y;
    int pos2X;
    int pos2Y;
    Node(int pos1X, int pos1Y, int pos2X, int pos2Y) {
        this->pos1X = pos1X;
        this->pos1Y = pos1Y;
        this->pos2X = pos2X;
        this->pos2Y = pos2Y;
    }
};

vector<Node> getNextPos(Node pos, vector<vector<int> > board) {
    vector<Node> nextPos; // 반환 결과 (이동 가능한 위치들)
    // (상, 하, 좌, 우)로 이동하는 경우에 대해서 처리
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int pos1NextX = pos.pos1X + dx[i];
        int pos1NextY = pos.pos1Y + dy[i];
        int pos2NextX = pos.pos2X + dx[i];
        int pos2NextY = pos.pos2Y + dy[i];
        // 이동하고자 하는 두 칸이 모두 비어 있다면
        if (board[pos1NextX][pos1NextY] == 0 && board[pos2NextX][pos2NextY] == 0) {
            nextPos.push_back(Node(pos1NextX, pos1NextY, pos2NextX, pos2NextY));
        }
    }
    // 현재 로봇이 가로로 놓여 있는 경우
    int hor[] = {-1, 1};
    if (pos.pos1X == pos.pos2X) {
        for (int i = 0; i < 2; i++) { // 위쪽으로 회전하거나, 아래쪽으로 회전
            // 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
            if (board[pos.pos1X + hor[i]][pos.pos1Y] == 0 && board[pos.pos2X + hor[i]][pos.pos2Y] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X + hor[i], pos.pos1Y));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X + hor[i], pos.pos2Y));
            }
        }
    }
    // 현재 로봇이 세로로 놓여 있는 경우
    int ver[] = {-1, 1};
    if (pos.pos1Y == pos.pos2Y) {
        for (int i = 0; i < 2; i++) { // 왼쪽으로 회전하거나, 오른쪽으로 회전
            // 왼쪽 혹은 오른쪽 두 칸이 모두 비어 있다면
            if (board[pos.pos1X][pos.pos1Y + ver[i]] == 0 && board[pos.pos2X][pos.pos2Y + ver[i]] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X, pos.pos1Y + ver[i]));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X, pos.pos2Y + ver[i]));
            }
        }
    }
    // 현재 위치에서 이동할 수 있는 위치를 반환
    return nextPos;
}

int solution(vector<vector<int> > board) {
    // 맵의 외곽에 벽을 두는 형태로 맵 변형
    int n = board.size();
    vector<vector<int> > newBoard(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }
    // 너비 우선 탐색(BFS) 수행
    queue<pair<Node, int> > q;
    vector<Node> visited;
    Node pos = Node(1, 1, 1, 2); // 시작 위치 설정
    q.push({pos, 0}); // 큐에 삽입한 뒤에
    visited.push_back(pos); // 방문 처리
    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        Node pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        // (n, n) 위치에 로봇이 도달했다면, 최단 거리이므로 반환
        if ((pos.pos1X == n && pos.pos1Y == n) || (pos.pos2X == n && pos.pos2Y == n)) {
            return cost;
        }
        // 현재 위치에서 이동할 수 있는 위치 확인
        vector<Node> nextPos = getNextPos(pos, newBoard);
        for (int i = 0; i < nextPos.size(); i++) {
            // 아직 방문하지 않은 위치라면 큐에 삽입하고 방문 처리
            bool check = true;
            Node pos = nextPos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (pos.pos1X == visited[j].pos1X && pos.pos1Y == visited[j].pos1Y && pos.pos2X == visited[j].pos2X && pos.pos2Y == visited[j].pos2Y) {
                    check = false;
                    break;
                }
            }
            if (check) {
                q.push({pos, cost + 1});
                visited.push_back(pos);
            }
        }
    }
    return 0;
}
