str1 = input()
str2 = input()

# 최소 편집 거리 계산을 위한 다이나믹 프로그래밍
def edit_dist(str1, str2):
    n = len(str1)
    m = len(str2)

    # 이차원 테이블을 초기화
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(m + 1):
            # 문자열 A가 비어 있다면, 문자열 B로 모든 문자를 삽입
            if i == 0:
                dp[i][j] = j
            # 문자열 B가 비어 있다면, 문자열 A로 모든 문자를 삽입
            elif j == 0:
                dp[i][j] = i
            # 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 가져옴
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            # 마지막 문자가 다르다면, 모든 경우의 수 중에서 최솟값 찾기
            else: # 삽입, 삭제, 교체 중에서 최소 비용을 찾아 삽입
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])

    return dp[n][m]

print(edit_dist(str1, str2))
