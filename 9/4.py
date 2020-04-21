# 노드의 개수 및 간선의 개수를 입력 받습니다.
n, m = map(int, input().split())
# 2차원 리스트를 만들고, 모든 값을 무한으로 초기화합니다.
adj = [[1e9] * (n + 1) for _ in range(n + 1)]

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화합니다.
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            adj[a][b] = 0

# 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화합니다.
for _ in range(m):
    # A와 B가 서로에게 가는 비용은 1이라고 설정합니다.
    a, b = map(int, input().split())
    adj[a][b] = 1
    adj[b][a] = 1

# 거쳐 갈 노드 x와 최종 목적지 노드 k를 입력 받습니다.
x, k = map(int, input().split())

# 플로이드 워셜 알고리즘을 정의합니다.
def solve():
    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                adj[a][b] = min(adj[a][b], adj[a][k] + adj[k][b])

# 플로이드 워셜 알고리즘을 수행합니다.
solve()

# 수행된 결과를 출력합니다.
distance = adj[1][k] + adj[k][x]
if distance >= 1e9:
    print("-1")
else:
    print(distance)
