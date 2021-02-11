#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 문제이다.
    이 문제도 보면 "점수의 최댓값"을 구하라고 한다.
    그리디는 보통 "가장 큰", "가장 긴", "가장 빠른"을 구하라는 것이 많다. (정렬을 필수로 함)

    1. 점수 순으로 내림차순 정렬
    2. 높은 점수순으로 해당 과제를 최대한 늦게 하는 날짜에 과제를 함.(4일까지면 4->3->2->1 날짜순으로 검사)
*/

int N;
int visit[1001];

struct Assignment {
    int day, point;
    bool operator<(const Assignment& b) const {
        if (point == b.point) return day < b.day;
        return point > b.point;
    }
};

vector<Assignment> a;
void getInput() {
    cin >> N;
    int i, j, day, score;
    for (i = 0; i < N; i++) {
        cin >> day >> score;
        a.push_back({ day, score });
    }
    sort(a.begin(), a.end());
    // cout << endl;
    // for(i=0; i<N; i++) {
    //     cout << a[i].day << " " << a[i].point << endl;
    // }
    // cout << endl;
}

void Solve() {
    int i, j, total = 0;
    for (i = 0; i < N; i++) {
        int d = a[i].day;
        for (j = d; j >= 1; j--) {
            if (visit[j] == 0) {
                visit[j] = a[i].point;
                total = total + a[i].point;
                break;
            }
        }
    }
    cout << total << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    getInput();
    Solve();


    return 0;
}