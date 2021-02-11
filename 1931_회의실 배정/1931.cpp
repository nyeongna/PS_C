#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 문제.
    그리디 문제는 아이디어 문제가 많은데, 어디를 기준으로 Sort하는 것이 "관건"

    "회의실"을 사용할 수 있는 "회의의 최대 갯수"를 찾는 문제이다.
    -즉, 끝나는 시간을 기준으로 오름차순 SORT 하고 차례대로 배정해본다.
*/


pair<int, int> a[100003];

bool Comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    int i, j;
    for (i = 1; i <= N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + N, Comp);

    int cnt = 0;
    int Time = 0;

    for (i = 1; i <= N; i++) {
        if (a[i].first >= Time) {
            Time = a[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}