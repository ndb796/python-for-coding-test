# 행(Row)이 3개인 2차원 리스트로 인접 리스트 표현
array = [[] for _ in range(3)]

# 노드 1에 연결된 노드 정보 저장 (노드, 거리)
array[0].append((2, 7))
array[0].append((3, 5))

# 노드 2에 연결된 노드 정보 저장 (노드, 거리)
array[1].append((1, 7))

# 노드 3에 연결된 노드 정보 저장 (노드, 거리)
array[2].append((1, 5))

print(array)
