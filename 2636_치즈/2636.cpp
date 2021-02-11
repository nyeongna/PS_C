#include <bits/stdc++.h>
using namespace std;

/*
    1. 관건은 바깥 공기를 찾는 것이다.
    2. 하지만 문제에서는 가장자리가 비어 있으므로 DFS(1,1) / BFS(1,1) 한번 실행시키면 치즈 가장자리 공기만 골라낼 수 있다.
    3. 그렇게 치즈 바깥면만 녹이고 갯수 세고를 반복한다.
*/

int m, n;
int graph[101][101];
int visit[101][101];
int tmp[101][101];
int cheese_num;

int x_dir[] = { -1,0,1,0 };
int y_dir[] = { 0,1,0,-1 };

void getInput() {
    int i, j;
    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) cheese_num++;
        }
    }
}
void DFS(int x, int y) {
    int i;
    if (graph[x][y] == 1) {
        visit[x][y] = 2;
        return;
    }
    for (i = 0; i < 4; i++) {
        int dx = x + x_dir[i];
        int dy = y + y_dir[i];
        if (dx >= 1 && dx <= m && dy >= 1 && dy <= n && visit[dx][dy] == 0) {
            visit[dx][dy] = 1;
            DFS(dx, dy);
        }
    }
}
void Melt() {
    memset(visit, 0, sizeof(visit));
    DFS(1, 1);

    int i, j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (visit[i][j] == 2) {
                graph[i][j] = 0;
                cheese_num--;
            }
        }
    }
}
void Solve() {
    int i, j, cnt = 0, last;
    while (cheese_num != 0) {
        cnt++;
        last = cheese_num;
        Melt();
    }
    cout << cnt << endl;
    cout << last << endl;
}
int main() {
    getInput();
    Solve();
    return 0;
}