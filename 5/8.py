# DFS 함수 정의
def dfs(adj, v, visited):
    # 현재 노드를 방문 처리
    visited.add(v)
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in adj[v]:
        if i not in visited:
            dfs(adj, i, visited)

# 각 노드가 연결된 정보를 dict 자료형으로 표현 (2차원 리스트 대신)
adj = {
  1: [2, 3, 8],
  2: [1, 7],
  3: [1, 4, 5],
  4: [3, 5],
  5: [3, 4],
  6: [7],
  7: [2, 6, 8],
  8: [1, 7]
}
# 각 노드가 방문된 정보를 set 자료형으로 표현 (1차원 리스트 대신)
visited = set()

# 정의된 DFS 함수 호출
dfs(adj, 1, visited)
