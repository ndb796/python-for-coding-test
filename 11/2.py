str = input()

# 첫 번째 문자를 숫자로 변경하여 대입
result = int(str[0])

for i in range(1, len(str)):
    # 두 수 중에서 하나라도 '0' 혹은 '1'인 경우, 곱하기보다는 더하기 수행
    if str[i] == '0' or str[i] == '1' or result <= 1:
        result += int(str[i])
    else:
        result *= int(str[i])

print(result)
