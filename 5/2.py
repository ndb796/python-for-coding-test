from collections import deque 

# 큐(Queue) 구현을 위해 deque 라이브러리 사용
queue = deque()

# 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
queue.append(5)
queue.append(2)
queue.append(3)
queue.append(7)
queue.popleft()
queue.append(1)
queue.append(4)
queue.popleft()

print(queue) # 최하단 원소부터 출력
queue.reverse() # 최상단 원소부터 출력하기 위해 역순으로 바꾸기
print(queue) # 최상단 원소부터 출력
