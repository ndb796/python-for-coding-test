#include <bits/stdc++.h>

using namespace std;

void heapSort(vector<int>& arr) {
    priority_queue<int> h;
    // 모든 원소를 차례대로 힙에 삽입
    for (int i = 0; i < arr.size(); i++) {
        h.push(-arr[i]);
    }
    // 힙에 삽입된 모든 원소를 차례대로 꺼내어 출력
    while (!h.empty()) {
        printf("%d\n", -h.top());
        h.pop();
    }
}

int n;
vector<int> arr;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }
    heapSort(arr);
}
