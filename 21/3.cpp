#include <bits/stdc++.h>

using namespace std;

// 전체 데이터의 개수는 최대 1,000,000개
long long arr[1000001], tree[1000001];
// 데이터의 개수(n), 변경 횟수(m), 구간 합 계산 횟수(k)
int n, m, k;

// i번째 수까지의 누적 합을 계산하는 함수
long long prefixSum(int i) {
    long long result = 0;
    while(i > 0) {
        result += tree[i];
        // 0이 아닌 마지막 비트만큼 빼가면서 이동
        i -= (i & -i);
    }
    return result;
} 

// i번째 수를 dif만큼 더하는 함수
void update(int i, long long dif) {
    while(i <= n) {
        tree[i] += dif;
        i += (i & -i);
    }
}

// start부터 end까지의 구간 합을 계산하는 함수
long long intervalSum(int start, int end) {
    return prefixSum(end) - prefixSum(start - 1);
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        arr[i] = x;
        update(i, x);
    }
    int count = 0;
    while(count++ < m + k) {
        int op;
        scanf("%d", &op);
        // 업데이트(update) 연산인 경우
        if(op == 1) {
            int index;
            long long value;
            scanf("%d %lld", &index, &value);
            update(index, value - arr[index]); // 바뀐 크기(dif)만큼 적용
            arr[index] = value; // i번째 수를 value로 업데이트
        }
        // 구간 합(interval sum) 연산인 경우
        else {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", intervalSum(start, end));
        }
    }
    return 0;
}
