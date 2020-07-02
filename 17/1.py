INF = int(1e9) # 무한을 의미하는 값으로 10억을 설정합니다.

# 노드의 개수 및 간선의 개수를 입력 받습니다.
n = int(input())
m = int(input())
# 2차원 리스트(그래프 표현)를 만들고, 모든 값을 무한으로 초기화합니다.
graph = [[INF] * (n + 1) for _ in range(n + 1)]

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화합니다.
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

# 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화합니다.
for _ in range(m):
    # A에서 B로 가는 비용은 C라고 설정합니다.
    a, b, c = map(int, input().split())
    # 가장 짧은 간선 정보만 저장합니다.
    if c < graph[a][b]:
        graph[a][b] = c

# 점화식에 따라 플로이드 워셜 알고리즘을 수행합니다.
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

# 수행된 결과를 출력합니다.
for a in range(1, n + 1):
    for b in range(1, n + 1):
        # 도달할 수 없는 경우, 0을 출력합니다.
        if graph[a][b] == INF:
            print(0, end=" ")
        # 도달할 수 있는 경우 거리를 출력합니다.
        else:
            print(graph[a][b], end=" ")
    print()
