#include <bits/stdc++.h>

using namespace std;

string str;

int main(void) {
    cin >> str;

    // 첫 번째 문자를 숫자로 변경한 값을 대입
    long long result = str[0] - '0';

    for (int i = 1; i < str.size(); i++) {
        // 두 수 중에서 하나라도 '0' 혹은 '1'인 경우, 곱하기보다는 더하기 수행
        int num = str[i] - '0';
        if (num <= 1 || result <= 1) {
            result += num;
        }
        else {
            result *= num;
        }
    }

    cout << result << '\n';
}
