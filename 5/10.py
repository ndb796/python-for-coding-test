# N, M을 공백을 기준으로 구분하여 입력 받기
n, m = map(int, input().split())
# 2차원 리스트의 맵 정보 입력 받기
array = []
for i in range(n):
    array.append(list(map(int, input())))

# DFS로 특정한 노드를 방문한 뒤에 연결된 모든 노드들도 방문
def dfs(x, y):
    # 주어진 범위를 벗어나는 경우에는 즉시 종료
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return 0
    if array[x][y] == 0:
        # 해당 노드 방문 처리
        array[x][y] = 1
        # 상, 하, 좌, 우의 위치들도 모두 방문 처리
        dfs(x - 1, y)
        dfs(x, y - 1)
        dfs(x + 1, y)
        dfs(x, y + 1)
        return 1
    return 0

# 모든 노드에 대하여 음료수 채우기
result = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == 1:
            result += 1
print(result)
