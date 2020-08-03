#include <bits/stdc++.h>

using namespace std;

long long d[100];

long long fibo(int x) {
    cout << "f(" << x << ") ";
    if (x == 1 || x == 2) {
        return 1;
    }
    if (d[x] != 0) {
        return d[x];
    }
    d[x] = fibo(x - 1) + fibo(x - 2);
    return d[x];
}

int main(void) {
    fibo(6);
}