# 정수 N을 입력 받기
n = int(input())
# 한 번 계산된 결과를 메모이제이션(Memoization)하기 위한 리스트 초기화
d = [0] * 1000001

# 다이나믹 프로그래밍(Dynamic Programming) 진행 (Bottom-top)
d[1] = 1
d[2] = 3
for i in range(3, n + 1):
    d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796

# 계산된 결과 출력
print(d[n])
