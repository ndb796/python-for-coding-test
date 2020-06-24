n = int(input())
data = list(map(int, input().split()))
# 순서를 바꾸어 '최장 증가 부분 수열' 문제로 변환
data.reverse()

# LCS 알고리즘 수행
dp = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if data[j] < data[i]:
            dp[i] = max(dp[i], dp[j] + 1)

# 열외해야 하는 병사의 최소 수를 출력
print(n - max(dp))
