#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디(Greedy) 문제이다.
    "최소의 강의실"을 사용해서 "모든 수업"을 가능하게 해야함.
    강의 "시작 시간"을 기준으로 정렬해야함.
    왜 "끝나는 시간"을 기준으로 정렬하면 안되는지 모르겠음....

    * 이전 수업과 다음 수업의 텀(term)을 "최소화"해야 "최소의 강의실"을 사용해서 모든 수업을 들을 수 있다.
    * 따라서 "시작 시간"을 기준으로 정렬한다....
    * "끝난 시간"을 기준으로 해버리면 이 수업이 언제적 수업인지 모르니까 순서가 꼬인다.
    * 반례) (1,5), (2,3), (4,8), (6,7)
*/

int N;
struct Class {
    // s = 시작 시간, t = 끝난 시간
    int s, t;
    bool operator<(const Class& b) const {
        if (t == b.t) return s < b.s;
        return t < b.t;
    }
};

// input 수업들을 저장할 class 벡터
vector<Class> a(200001);

void getInput() {
    cin >> N;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> a[i].s >> a[i].t;
    }
    sort(a.begin(), a.begin() + N);
    // for (i = 0; i < N; i++) {
    //     cout << a[i].s << " " << a[i].t << endl;
    // }
}

void Solve() {
    // 수업의 끝난 시간을 기준으로 하는 min heap
    priority_queue<int, vector<int>, greater<int>> pQ;

    // 첫번째 수업을 pQ에 push
    pQ.push(a[0].t);

    // 강의실 갯수는 '1'부터 시작
    int i, j, cnt = 1;

    for (i = 1; i < N; i++) {
        //  [ pQ.top()이 a[i].s보다 크므로 ] 새로운 강의실을 만들어야 하는 상황
        if (pQ.top() > a[i].s) {
            pQ.push(a[i].t);
            cnt++;
        }
        //  [ pQ.top()이 a[i].s보다 작거나 ] 같으므로 강의실을 또 쓸 수 있음.
        else {
            pQ.pop();
            pQ.push(a[i].t);
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}