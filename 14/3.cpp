#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<int, double> > v;
    vector<int> answer;
    int length = stages.size();

    // 스테이지 번호를 1부터 N까지 증가시키며
    for (int i = 1; i <= N; i++) {
        // 해당 스테이지에 머물러 있는 사람의 수 계산
        int cnt = count(stages.begin(), stages.end(), i);

        // 실패율 계산
        double fail = 0;
        if (length >= 1) {
            fail = (double) cnt / length;
        }

        // 리스트에 (스테이지 번호, 실패율) 원소 삽입
        v.push_back({i, fail});
        length -= cnt;
    }

    // 실패율을 기준으로 각 스테이지를 내림차순 정렬
    sort(v.begin(), v.end(), compare);

    // 정렬된 스테이지 번호 반환
    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].first);
    }
    return answer;
}