def recursive_function(i):
    # 100번째 출력을 했을 때 종료되도록 종료 조건 명시
    if i == 100:
        return
    print('재귀 함수를 호출합니다.')
    recursive_function(i + 1)

recursive_function(0)
