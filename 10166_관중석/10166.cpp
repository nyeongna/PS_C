#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int d1, d2;
int visit[2001][2001];

/*
    모든 좌석은 분수꼴로 나타낼 수 있다.
    이 분수꼴을 모두 기약분수로 나타내면 겹치는 자리와 안겹치는 자리를 구분할 수 있다.
    d1=3일때 세 자리는 1/3, 2/3, 3/3 으로 나타낼 수 있고 기약분수는 1/3, 2/3, 1/1 이다.
    visit[1][3], visit[2][3], visit[1][1] 을 방문했다고 가정하면 다음에 저 자리에 해당하는 숫자가 나와도 카운트 안하면 된다.
*/

void getInput() {
    cin >> d1 >> d2;
}
int GCD(int a, int b) {
    return b != 0 ? GCD(b, a % b) : a;
}
int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

void Solve() {
    int i, j, ans = 0;
    for (i = d1; i <= d2; i++) {
        for (j = 1; j <= i; j++) {
            int gcd = GCD(i, j);
            if (visit[j / gcd][i / gcd] == 0) {
                visit[j / gcd][i / gcd] = 1;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    getInput();
    Solve();
    return 0;
}