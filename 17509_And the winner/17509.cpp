#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 알고리즘
    패널티 T + 20V 에서 틀린 횟수 V는 언제나 똑같으므로 무시해도 된다.
    중요한것은 T(흐른 시간)이다. 즉, 오래 걸리는 문제를 먼저 풀어버리면 나중에 적게 걸리는 문제를 풀어도 페널티를 크게 먹는다.
    따라서 적게 걸리는 문제를 먼저 풀어서 나중에 오래 걸리는 문제를 풀어도 "페널티를 적게 먹는 쪽"으로 해야함.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j;
    int D,V;
    pair<int,int> a[11];
    for(i=0; i<11; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+11);
    int total=0;
    int Time=0;
    for(i=0; i<11; i++) {
        total = total + (a[i].first+Time) + a[i].second * 20;
        Time = Time + a[i].first;
    }
    cout << total << endl;
    return 0;
}