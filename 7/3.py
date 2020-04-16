# 이진 탐색 소스코드 구현
def binary_search(start, end, target, array):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return None

# n(원소의 개수)과 target(찾고자 하는 문자열)을 입력 받기
n, target = list(map(int, input().split()))
# 전체 원소 입력 받기
array = list(map(int, input().split()))

# 이진 탐색 수행 결과 출력
result = binary_search(0, n - 1, target, array)
if result == None:
    print(None)
else:
    print(result + 1)
