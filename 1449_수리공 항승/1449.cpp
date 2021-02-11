#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 알고리즘
    정렬이 중요하다. 먼저 물의 새는 위치를 오름차순으로 정렬하고. 차례대로 가능한만큼 테이프를 붙히다보면
    이것이 곧 최소한의 갯수가 된다.
*/
int N, L;
int a[1001];

void Solve() {
    int i, j, cnt = 0;
    int init;

    for (i = 0; i < N; i++) {
        // 테이프를 붙이다.(a[i] 의 옆으로 -0.5cm부터 붙임)
        cnt++;

        // 테이프를 붙일 시작점 (a[i]의 옆으로 -0.5cm부터 붙임)
        init = a[i];

        // "다음 물 새는 지점"부터 검사를 해서 테이프의 길이 L안에 가능하면 포함시킨다.
        for (j = i + 1; j < N; j++) {
            if (a[j] - init <= L - 1) {
                i++;
            }
            // 그 다음 물새는 지점은 포함안된다면 break하고 새로운 테이프를 붙일 준비를 한다.
            else break;
        }
    }
    cout << cnt << endl;
}
void getInput() {
    cin >> N >> L;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }
    // 먼저 물 새는 곳의 위치를 오름차순으로 정렬한다.
    sort(a, a + N);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();

    return 0;
}