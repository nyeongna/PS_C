#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int n;
char graph[51][51];
char tmp[51][51];
int visit[51][51];

void getInput() {
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
}
void Copy() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            tmp[i][j] = graph[i][j];
        }
    }
}
int max_num = -2147000000;

void Check(int x, int y) {
    int total = 1;
    for (int i = y; i < n; i++) {
        if (tmp[x][i] == tmp[x][i + 1]) {
            //cout << x << " " << i  << " "<<tmp[x][i] << " " << tmp[x][i+1] << " ";
            total++;
            visit[x][i] = 1;
        }
        else break;
    }
    //cout << total << endl;
    max_num = max(max_num, total);
}

void Check2(int x, int y) {
    int total = 1;
    for (int i = x; i < n; i++) {
        if (tmp[i][y] == tmp[i + 1][y]) {
            //cout << x << " " << i  << " "<<tmp[x][i] << " " << tmp[x][i+1] << " ";
            total++;
            visit[i][y] = 1;
        }
        else break;
    }
    //cout << total << endl;
    if (max_num <= total) {
        max_num = max(max_num, total);
        //cout << x << " " << y << " " << total << endl;
    }
}

void PrintTmp() {
    int i, j;
    cout << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
}

void Change(int x1, int y1, int x2, int y2) {
    memset(visit, 0, sizeof(visit));
    Copy();
    tmp[x1][y1] = graph[x2][y2];
    tmp[x2][y2] = graph[x1][y1];
    //PrintTmp();

    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (visit[i][j] == 0) {
                visit[i][j] = 1;
                Check(i, j);
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (visit[i][j] == 0) {
                visit[i][j] = 1;
                Check2(i, j);
            }
        }
    }
}
void Solve() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j < n; j++) {
            Change(i, j, i, j + 1);
            Change(j, i, j+1, i);
        }
    }
    cout << max_num << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}