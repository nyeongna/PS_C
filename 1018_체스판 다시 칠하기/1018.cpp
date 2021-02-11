#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int ans = 2147000000;
char graph[51][51];
char W[9][9];
char B[9][9];

void Check(int a, int b) {
    int i, j;
    int x=1, y=1;
    int white=0, black=0;
    for(i=a; i<=a+7; i++) {
        y=1;
        for(j=b; j<=b+7; j++) {
            if (W[x][y] != graph[i][j]) white++;
            if (B[x][y] != graph[i][j]) black++;
            y++;
        }
        x++;
    }
    //cout << a << " " << b << " " << white << " " << black << endl;
    int final = min(white, black);
    ans = min(ans, final);
}

void Print() {
    int i, j;
    cout << endl;
    for (i = 1; i <= 8; i++) {
        for(j=1; j<=8; j++) {
            cout << W[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(i=1; i<=8; i++) {
        for(j=1; j<=8; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m, n;
    int i, j;
    cin >> m >> n;
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                W[i][j] = 'W';
                B[i][j] = 'B';
            }
            else if (i % 2 == 1 && j % 2 == 0) {
                W[i][j] = 'B';
                B[i][j] = 'W';
            }
            else if (i % 2 == 0 && j % 2 == 1) {
                W[i][j] = 'B';
                B[i][j] = 'W';
            }
            else {
                W[i][j] = 'W';
                B[i][j] = 'B';
            }
        }
    }
    for (i = 1; i <= m;i++) {
        for (j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    //Print();
    for (i = 1; i <= m - 7; i++) {
        for (j = 1; j <= n - 7; j++) {
            Check(i, j);
        }
    }
    cout << ans << endl;

    return 0;
}