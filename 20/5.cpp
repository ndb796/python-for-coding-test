#include <bits/stdc++.h>

using namespace std;

int n = 5; // 데이터의 개수 N과 데이터 입력받기
int arr[] = {10, 20, 30, 40, 50};
int prefixSum[6];

int main() {
    // 접두사 합(Prefix Sum) 배열 계산
    int sumValue = 0;

    for (int i = 0; i < n; i++) {
        sumValue += arr[i];
        prefixSum[i + 1] = sumValue;
    }

    // 구간 합 계산(세 번째 수부터 네 번째 수까지)
    int left = 3;
    int right = 4;
    cout << prefixSum[right] - prefixSum[left - 1] << '\n';
}
