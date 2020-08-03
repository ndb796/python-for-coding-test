#include <bits/stdc++.h>

using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}