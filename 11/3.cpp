#include <bits/stdc++.h>

using namespace std;

string str;
int count0 = 0; // 전부 0으로 바꾸는 경우
int count1 = 0; // 전부 1로 바꾸는 경우

int main(void) {
    cin >> str;

    // 첫 번째 원소에 대해서 처리
    if (str[0] == '1') {
        count0 += 1;
    }
    else {
        count1 += 1;
    }

    // 두 번째 원소부터 모든 원소를 확인하며
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] != str[i + 1]) {
            // 다음 수에서 1로 바뀌는 경우
            if (str[i + 1] == '1') count0 += 1;
            // 다음 수에서 0으로 바뀌는 경우
            else count1 += 1;
        }
    }

    cout << min(count0, count1) << '\n';
}