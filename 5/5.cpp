#include <bits/stdc++.h>

using namespace std;

// 반복적으로 구현한 n!
int factorialIterative(int n) {
    int result = 1;
    // 1부터 n까지의 수를 차례대로 곱하기
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 재귀적으로 구현한 n!
int factorialRecursive(int n) {
    // n이 1 이하인 경우 1을 반환
    if (n <= 1) return 1;
    // n! = n * (n - 1)!를 그대로 코드로 작성하기
    return n * factorialRecursive(n - 1);
}

int main(void) {
    // 각각의 방식으로 구현한 n! 출력(n = 5)
    cout << "반복적으로 구현:" << factorialIterative(5) << '\n';
    cout << "재귀적으로 구현:" << factorialRecursive(5) << '\n';
}