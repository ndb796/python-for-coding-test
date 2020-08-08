#include <bits/stdc++.h>

using namespace std;

// 현재 설치된 구조물이 '가능한' 구조물인지 확인하는 함수
bool possible(vector<vector<int> > answer) {
    for (int i = 0; i < answer.size(); i++) {
        int x = answer[i][0];
        int y = answer[i][1];
        int stuff = answer[i][2];
        if (stuff == 0) { // 설치된 것이 '기둥'인 경우
            bool check = false;
            // '바닥 위'라면 정상
            if (y == 0) check = true;
            // '보의 한 쪽 끝 부분 위' 혹은 '다른 기둥 위'라면 정상
            for (int j = 0; j < answer.size(); j++) {
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    check = true;
                }
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    check = true;
                }
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
                    check = true;
                }
            }
            if (!check) return false; // 아니라면 거짓(False) 반환
        }
        else if (stuff == 1) { // 설치된 것이 '보'인 경우
            bool check = false;
            bool left = false;
            bool right = false;
            // '한쪽 끝부분이 기둥 위' 혹은 '양쪽 끝부분이 다른 보와 동시에 연결'이라면 정상
            for (int j = 0; j < answer.size(); j++) {
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
                    check = true;
                }
                if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
                    check = true;
                }
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    left = true;
                }
                if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    right = true;
                }
            }
            if (left && right) check = true;
            if (!check) return false; // 아니라면 거짓(False) 반환
        }
    }
    return true;
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;
    // 작업(frame)의 개수는 최대 1,000개
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int stuff = build_frame[i][2];
        int operate = build_frame[i][3];
        if (operate == 0) { // 삭제하는 경우
            // 일단 삭제를 해 본 뒤에
            int index = 0;
            for (int j = 0; j < answer.size(); j++) {
                if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
                    index = j;
                }
            }
            vector<int> erased = answer[index];
            answer.erase(answer.begin() + index);
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.push_back(erased); // 가능한 구조물이 아니라면 다시 설치
            }
        }
        if (operate == 1) { // 설치하는 경우
            // 일단 설치를 해 본 뒤에
            vector<int> inserted;
            inserted.push_back(x);
            inserted.push_back(y);
            inserted.push_back(stuff);
            answer.push_back(inserted);
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.pop_back(); // 가능한 구조물이 아니라면 다시 제거
            }
        }
    }
    // 정렬된 결과를 반환
    sort(answer.begin(), answer.end());
    return answer;
}