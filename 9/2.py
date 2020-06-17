import heapq
import sys
input = sys.stdin.readline
INF = int(1e9) # 무한을 의미하는 값으로 10억을 설정합니다.

# 노드의 개수, 간선의 개수를 입력 받습니다.
n, m = map(int, input().split())
# 시작 노드 번호를 입력 받습니다.
start = int(input())
# 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만듭니다.
graph = [[] for i in range(n + 1)]
# 최단 거리 테이블을 모두 무한으로 초기화합니다.
distance = [INF] * (n + 1)

# 모든 간선 정보를 입력 받습니다.
for _ in range(m):
    a, b, c = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c라는 의미입니다.
    graph[a].append((b, c))

def dijkstra(start):
   q = []
   # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입합니다.
   heapq.heappush(q, (0, start))
   distance[start] = 0
   while q: # 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보를 꺼냅니다.
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시합니다.
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인합니다.
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

# 다익스트라 알고리즘을 수행합니다.
dijkstra(start)

# 모든 노드로 가기 위한 최단 거리를 출력합니다.
for i in range(1, n + 1):
    # 도달할 수 없는 경우, 무한(INFINITY)이라고 출력합니다.
    if distance[i] == INF:
        print("INFINITY")
    # 도달할 수 있는 경우 거리를 출력합니다.
    else:
        print(distance[i])
