#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int graph[101][101][101];
int visit[101][101][101];

int x_dir[] = { -1, 0, 1, 0, 0, 0 };
int y_dir[] = { 0, 1, 0,-1, 0, 0 };
int z_dir[] = { 0, 0, 0, 0, 1,-1 };

typedef struct {
    int x, y, z, dist;
} Tomato;

queue<Tomato> Q;

void getInput() {
    cin >> n >> m >> h;
    int i, j, k;
    for (k = 1; k <= h; k++) {
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) {
                    Q.push({ i,j,k,1 });
                }
            }
        }
    }
}

void Print() {
    int i, j, k;
    cout << endl;
    for (k=1; k<=h; k++) {
        for(i=1; i<=m; i++) {
            for(j=1; j<=n; j++) {
                cout << graph[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
void Solve() {
    int i,j,k;
    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int z = Q.front().z;
        int dist = Q.front().dist;
        Q.pop();

        for (i = 0; i < 6; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            int dz = z + z_dir[i];
            if (dx>=1 && dx<=m && dy>=1 && dy<=n && dz>=1 && dz<=h && graph[dx][dy][dz] == 0) {
                graph[dx][dy][dz] = dist + 1;
                Q.push({dx,dy,dz, dist+1});
            }
        }
    }
    int flag=1;
    int max_num=-2147000000;
    for (k=1; k<=h; k++) {
        for(i=1; i<=m; i++) {
            for(j=1; j<=n; j++) {
                if (graph[i][j][k]==0) {
                    flag=0;
                }
                max_num = max(max_num, graph[i][j][k]);
            }
        }
    }
    //Print();
    if (flag) cout << max_num-1 << endl;
    else cout << -1 << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    getInput();
    Solve();
    return 0;
}