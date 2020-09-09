#include <bits/stdc++.h>

using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<string>& v, string leftValue, string rightValue) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

// 문자열 내에서 특정한 문자열을 다른 문자열로 모두 치환하는 함수
string replaceAll(string str, string from, string to){
    string res = str;
    int pos = 0;
    while((pos = res.find(from, pos)) != string::npos) 
    {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

// 모든 단어들을 길이마다 나누어서 저장하기 위한 리스트
vector<string> arr[10001];
// 모든 단어들을 길이마다 나누어서 뒤집어 저장하기 위한 리스트
vector<string> reversed_arr[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    // 모든 단어를 접미사 와일드카드 배열, 접두사 와일드카드 배열에 각각 삽입
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word); // 단어를 삽입
        reverse(word.begin(), word.end());
        reversed_arr[word.size()].push_back(word); // 단어를 뒤집어서 삽입
    }
    
    // 이진 탐색을 수행하기 위해 각 단어 리스트 정렬 수행
    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reversed_arr[i].begin(), reversed_arr[i].end());
    }
    
    // 쿼리를 하나씩 확인하며 처리
    for (int i = 0; i < queries.size(); i++) {
        string q = queries[i];
        int res = 0;
        if (q[0] != '?') { // 접미사에 와일드 카드가 붙은 경우
            res = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        else { // 접두사에 와일드 카드가 붙은 경우
            reverse(q.begin(), q.end());
            res = countByRange(reversed_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z")); 
        }
        // 검색된 단어의 개수를 저장
        answer.push_back(res);
    }
    return answer;
}