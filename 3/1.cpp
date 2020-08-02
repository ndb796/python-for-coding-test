#include <bits/stdc++.h>

using namespace std;

int n = 1260;
int cnt = 0;
int types[4] = {500, 100, 50, 10};

int main() {
    for (int i = 0; i < 4; i++) {
        int coin = types[i];
        cnt += n / coin;
        n %= coin;
    }
    cout << cnt << '\n';
}