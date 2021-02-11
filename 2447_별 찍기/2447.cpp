#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    분할정복
    출력 문제인데, 배열을 하나 만들어놓고 채워 넣는 것이 편하다!
*/

char a[7000][7000];
int n;

void Recur2(int x, int y, int n) {
    int i, j;
    for (i = x; i < x + n; i++) {
        for (j = y; j < y + n; j++) {
            a[i][j] = ' ';
        }
    }
}

void Recur(int x, int y, int n) {
    int i, j;
    if (n == 1) {
        a[x][y] = '*';
        return;
    }
    Recur(x, y, n / 3);
    Recur(x, y + n / 3, n / 3);
    Recur(x, y + n / 3 * 2, n / 3);

    Recur(x + n / 3, y, n / 3);
    Recur2(x + n / 3, y + n / 3, n / 3);
    Recur(x + n / 3, y + n / 3 * 2, n / 3);

    Recur(x + n / 3 * 2, y, n / 3);
    Recur(x + n / 3 * 2, y + n / 3, n / 3);
    Recur(x + n / 3 * 2, y + n / 3 * 2, n / 3);

}
void Print() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    // n은 3의 거듭제곱
    Recur(1, 1, n);
    Print();
    return 0;
}