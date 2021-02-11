#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int d1, d2;
int visit[2001][2001];

/*
    ��� �¼��� �м��÷� ��Ÿ�� �� �ִ�.
    �� �м����� ��� ���м��� ��Ÿ���� ��ġ�� �ڸ��� �Ȱ�ġ�� �ڸ��� ������ �� �ִ�.
    d1=3�϶� �� �ڸ��� 1/3, 2/3, 3/3 ���� ��Ÿ�� �� �ְ� ���м��� 1/3, 2/3, 1/1 �̴�.
    visit[1][3], visit[2][3], visit[1][1] �� �湮�ߴٰ� �����ϸ� ������ �� �ڸ��� �ش��ϴ� ���ڰ� ���͵� ī��Ʈ ���ϸ� �ȴ�.
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