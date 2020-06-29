# n번째 못생긴 수를 찾는 함수
def solve(n):
    ugly = [0] * n # 못생긴 수를 담기 위한 테이블 (1차원 DP 테이블)
    ugly[0] = 1 # 첫 번째 못생긴 수는 1

    # 2배, 3배, 5배를 위한 인덱스
    i2 = i3 = i5 = 0
    # 처음에 곱셈 값을 초기화
    next2, next3, next5 = 2, 3, 5

    # 1부터 n까지의 못생긴 수들을 찾기
    for l in range(1, n):
        # 가능한 곱셈 결과 중에서 가장 작은 수를 선택
        ugly[l] = min(next2, next3, next5)
        # 인덱스에 따라서 곱셈 결과를 증가
        if ugly[l] == next2:
            i2 += 1
            next2 = ugly[i2] * 2
        if ugly[l] == next3:
            i3 += 1
            next3 = ugly[i3] * 3
        if ugly[l] == next5:
            i5 += 1
            next5 = ugly[i5] * 5

    # n번째 못생긴 수를 출력
    return ugly[n - 1]

n = int(input())
print(solve(n))
