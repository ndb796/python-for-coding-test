# 노드의 개수 및 간선의 개수를 입력 받습니다.
n = int(input())
m = int(input())

# 2차원 리스트를 만들고, 모든 값을 무한으로 초기화합니다.
adj = [[1e9] * (n + 1) for _ in range(n + 1)]

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화합니다.
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            adj[a][b] = 0

# 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화합니다.
for _ in range(m):
    # A에서 B로 가는 비용은 C라고 설정합니다.
    a, b, c = map(int, input().split())
    adj[a][b] = c

# 플로이드 워셜 알고리즘을 정의합니다.
def solve():
    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                adj[a][b] = min(adj[a][b], adj[a][k] + adj[k][b])

# 플로이드 워셜 알고리즘을 수행합니다.
solve()

# 수행된 결과를 출력합니다.
for a in range(1, n + 1):
    for b in range(1, n + 1):
        # 도달할 수 없는 경우, 무한(INFINITY)이라고 출력합니다.
        if adj[a][b] == 1e9:
            print("INF", end=" ")
        # 도달할 수 있는 경우 거리를 출력합니다.
        else:
            print(adj[a][b], end=" ")
    print()
