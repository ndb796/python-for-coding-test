#include <bits/stdc++.h>

using namespace std;

class Fruit {
public:
    string name;
    int score;
    Fruit(string name, int score) {
        this->name = name;
        this->score = score;
    }
    // 정렬 기준은 '점수가 낮은 순서'
    bool operator <(Fruit &other) {
        return this->score < other.score; 
    }
};

int main(void) {
    int n = 3;
    Fruit fruits[] = {
        Fruit("바나나", 2),
        Fruit("사과", 5),
        Fruit("당근", 3)
    };
    sort(fruits, fruits + n);
    for(int i = 0; i < n; i++) {
        cout << '(' << fruits[i].name << ',' << fruits[i].score << ')' << ' ';
    }
}