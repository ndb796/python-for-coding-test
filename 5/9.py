from collections import deque

# BFS 함수 정의
def bfs(adj, start, visited):
    # 큐(Queue) 구현을 위해 deque 라이브러리 사용
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited.add(start)
    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력하기
        v = queue.popleft()
        print(v, end=' ')
        # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in adj[v]:
            if i not in visited:
                queue.append(i)
                visited.add(i)

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

# 정의된 BFS 함수 호출
bfs(adj, 1, visited)
