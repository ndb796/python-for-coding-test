#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main(void) {
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);
    q.pop();
    q.push(1);
    q.push(4);
    q.pop();
    // 먼저 들어온 원소부터 추출
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}
