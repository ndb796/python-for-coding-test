# 최소 편집 거리(Edit Distance) 계산을 위한 다이나믹 프로그래밍
def edit_dist(str1, str2):
    n = len(str1)
    m = len(str2)

    # 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # DP 테이블 초기 설정
    for i in range(1, n + 1):
        dp[i][0] = i
    for j in range(1, m + 1):
        dp[0][j] = j
    
    # 최소 편집 거리 계산
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            # 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 대입
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            # 문자가 다르다면, 세 가지 경우 중에서 최솟값 찾기
            else: # 삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

    return dp[n][m]

# 두 문자열을 입력 받기
str1 = input()
str2 = input()

# 최소 편집 거리 출력
print(edit_dist(str1, str2))
