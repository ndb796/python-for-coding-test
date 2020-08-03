# N 입력 받기
n = int(input())

count = [0] * 10001
result = -1 # 가장 많이 가지고 있는 신발 번호
max_value = 0 # 가장 많이 가지고 있는 신발 번호의 신발 개수

for i in range(n):
    a = int(input())
    count[a] += 1
    if max_value < count[a]:
        max_value = count[a]
        result = a # 가장 많이 가지고 있는 신발 번호 기록

print(result)
