#include <bits/stdc++.h>
using namespace std;

int n;
int graph[101][101];
int after[101][101];
int max_height=-2147000000;
int ans = -2147000000;

int x_dir[4] = {-1,0,1,0};
int y_dir[4] = {0,1,0,-1};

void getInput() {
    cin >> n;
    int i,j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cin >> graph[i][j];
            max_height = max(max_height, graph[i][j]);
        }
    }
}

void Rain(int height) {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if (graph[i][j] <= height) {
                after[i][j] = 1;
            }
        }
    }
}

void DFS(int x, int y) {
    int i;
    for(i=0; i<4; i++) {
        int dx = x + x_dir[i];
        int dy = y + y_dir[i];
        if (dx>=1 && dx<=n && dy>=1 && dy<=n && after[dx][dy]==0) {
            after[dx][dy]=1;
            DFS(dx,dy);
        }
    }
}

int checkIsland() {
    int i, j, cnt=0;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if (after[i][j]==0) {
                cnt++;
                after[i][j]=1;
                DFS(i,j);
            }
        }
    }
    return cnt;
}

void Reset() {
    memset(after, 0, sizeof(after));
}

void Solve() {
    int i;
    for(i=0; i<=max_height; i++) {
        Rain(i);
        ans = max(ans, checkIsland());
        Reset();
    }
    cout << ans << endl;
}

int main () {
    getInput();
    Solve();
    return 0;
}