from collections import deque

n, l, r = map(int, input().split())
data = []

for _ in range(n):
    data.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

result = 0

# 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
def process(x, y, index):
    routes = []
    routes.append((x, y))
    # DFS를 위한 큐 자료구조 정의
    q = deque()
    q.append((x, y))
    union[x][y] = index
    summary = data[x][y]
    count = 1
    # 큐가 빌 때까지 반복(BFS)
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 바로 옆 나라와 국경선이 열린 경우
            if 0 <= nx < n and 0 <= ny < n and union[nx][ny] == -1:
                if l <= abs(data[nx][ny] - data[x][y]) <= r:
                    union[nx][ny] = index
                    summary += data[nx][ny]
                    count += 1
                    q.append((nx, ny))
                    routes.append((nx, ny))
    # 연합 국가끼리 인구를 분배
    for i, j in routes:
        data[i][j] = summary // count
    return count

total_count = 0

# 더 이상 인구 이동을 할 수 없을 때까지 반복
while True:
    union = [[-1] * n for _ in range(n)]
    index = 0
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1: # 해당 나라가 아직 처리되지 않았다면
                process(i, j, index)
                index += 1

    # 모든 인구 이동이 끝난 경우
    if index == n * n:
        break

    total_count += 1

print(total_count)
