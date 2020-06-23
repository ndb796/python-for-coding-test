n = int(input())
a = list(map(int, input().split()))
a.sort()

# Median(가운데) 값을 출력합니다.
print(a[(n - 1) // 2])
