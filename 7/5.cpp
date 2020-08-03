#include <bits/stdc++.h>

using namespace std;

// 이진 탐색 소스코드 구현(반복문)
int binarySearch(vector<int> arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target) return mid;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target) end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else start = mid + 1; 
    }
    return -1;
}

// N(가게의 부품 개수)와 M(손님이 확인 요청한 부품 개수)
int n, m;
// 가게에 있는 전체 부품 번호들
vector<int> arr;
// 손님이 확인 요청한 부품 번호들
vector<int> targets;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }
    // 손님이 확인 요청한 부품 번호를 하나씩 확인
    for (int i = 0; i < m; i++) {
        // 해당 부품이 존재하는지 확인
        int result = binarySearch(arr, targets[i], 0, n - 1);
        if (result != -1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}