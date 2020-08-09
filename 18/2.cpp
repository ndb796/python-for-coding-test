#include <bits/stdc++.h>

using namespace std;

// 탑승구의 개수와 비행기의 개수
int g, p;
int parent[100001]; // 부모 테이블 초기화

// 특정 원소가 속한 집합을 찾기
int findParent(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> g >> p;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= g; i++) {
        parent[i] = i;
    }

    int result = 0;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        int root = findParent(x); // 현재 비행기의 탑승구의 루트 확인
        if (root == 0) break; // 현재 루트가 0이라면, 종료
        unionParent(root, root - 1); // 그렇지 않다면 바로 왼쪽의 집합과 합치기
        result += 1;
    }

    cout << result << '\n';
}