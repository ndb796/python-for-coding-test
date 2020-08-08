#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[50][50];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

// 치킨 거리의 합을 계산하는 함수
int getSum(vector<pair<int, int> > candidates) {
    int result = 0;
    // 모든 집에 대하여
    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        // 가장 가까운 치킨 집을 찾기
        int temp = 1e9;
        for (int j = 0; j < candidates.size(); j++) {
            int cx = candidates[j].first;
            int cy = candidates[j].second;
            temp = min(temp, abs(hx - cx) + abs(hy - cy));
        }
        // 가장 가까운 치킨 집까지의 거리를 더하기
        result += temp;
    }
    // 치킨 거리의 합 반환
    return result;
} 

int main(void) {
    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == 1) house.push_back({r, c}); // 일반 집
            else if (arr[r][c] == 2) chicken.push_back({r, c}); // 치킨집
        }
    }

    // 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
    vector<bool> binary(chicken.size());
    fill(binary.end() - m, binary.end(), true);

    // 치킨 거리의 합의 최소를 찾아 출력
    int result = 1e9;

    do {
        vector<pair<int, int> > now;
        for (int i = 0; i < chicken.size(); i++) {
            if (binary[i]) {
                int cx = chicken[i].first;
                int cy = chicken[i].second;
                now.push_back({cx, cy});
            }
        }
        result = min(result, getSum(now));
    } while(next_permutation(binary.begin(), binary.end()));

    cout << result << '\n';
}