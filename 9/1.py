import sys
input = sys.stdin.readline

# 노드의 개수, 간선의 개수를 입력 받습니다.
n, m = map(int, input().split())
# 시작 노드 번호를 입력 받습니다.
start = int(input())
# 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만듭니다.
adj = [[] for i in range (n + 1)]
# 방문한 적이 있는지 체크하는 목적의 리스트를 만듭니다.
visited = [False] * (n + 1)
# 최단 거리 테이블을 모두 무한(10억)으로 초기화합니다.
distance = [1e9] * (n + 1)
# 모든 간선 정보를 입력 받습니다.

for _ in range(m):
    a, b, c = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c라는 의미입니다.
    adj[a].append((b, c))

# 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환합니다.
def get_smallest_node():
    min_value = 1e9
    index = 0
    for i in range(1, n + 1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = i
    return index

def dijkstra(start):
    # 시작 노드에 대해서 초기화합니다.
    distance[start] = 0
    visited[start] = True
    for j in adj[start]:
        distance[j[0]] = j[1]
    # 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복합니다.
    for i in range(n - 1):
        # 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리합니다.
        now = get_smallest_node()
        visited[now] = True
        # 현재 노드와 연결된 다른 노드를 확인합니다.
        for j in adj[now]:
            cost = distance[now] + j[1]
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[j[0]]:
                distance[j[0]] = cost

# 다익스트라 알고리즘을 수행합니다.
dijkstra(start)

# 모든 노드로 가기 위한 최단 거리를 출력합니다.
for i in range (1, n + 1):
    # 도달할 수 없는 경우, 무한(INFINITY)이라고 출력합니다.
    if distance[i] == 1e9:
        print("INFINITY")
    # 도달할 수 있는 경우 거리를 출력합니다.
    else:
        print(distance[i])
