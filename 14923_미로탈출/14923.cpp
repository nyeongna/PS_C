#include <bits/stdc++.h>
using namespace std;

int m , n, hx, hy, ex, ey;
int graph[1001][1001];
int visit[1001][1001];
int x_dir[] = {-1,0,1,0};
int y_dir[] = {0,1,0,-1};

vector<pair<int,int>> wall;

void getInput() {
    cin >> m >> n;
    cin >> hx >> hy;
    cin >> ex >> ey;
    int i, j,k;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            cin >> graph[i][j];
        }
    }

}

typedef struct State{
    int x, y, dist, staff;
} State;

void BFS() {
    memset(visit, 0, sizeof(visit));
    queue<State> Q;
    Q.push({hx,hy,1, 1});
    visit[hx][hy]=1;
    int i;

    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        int staff = Q.front().staff;
        Q.pop();

        if (x==ex && y ==ey) {
            //cout << x<<y<<dist<<staff<<endl;
            cout << dist-1 << endl;
            return;
        }

        for(i=0; i<4; i++) {
            int dx = x+x_dir[i];
            int dy = y+y_dir[i];

            // visit
            // 1 == staff 있이 방문
            // 2 == staff 없이 방문
            // 0 == 방문 한 적 없음.

            // staff가 있고 빈칸으로 감(빈칸은 staff 없이 온 사람이 먼저 왔을 수 있음)
            if (dx>=1 && dx<=m && dy>=1 && dy<=n && staff==1 && (visit[dx][dy]==0 || visit[dx][dy]==2) && graph[dx][dy]==0) {
                visit[dx][dy] = 1;
                Q.push({dx,dy,dist+1,staff});
            }

            // staff가 있고 벽으로 감
            if (dx>=1 && dx<=m && dy>=1 && dy<=n && staff==1 && visit[dx][dy]==0 && graph[dx][dy]==1) {
                visit[dx][dy] = 2;
                Q.push({dx,dy,dist+1,0});
            }

            // staff 없고 빈칸으로 감
            if (dx>=1 && dx<=m && dy>=1 && dy<=n && staff==0 && visit[dx][dy]==0 && graph[dx][dy]==0) {
                visit[dx][dy] = 2;
                Q.push({dx,dy,dist+1, staff});
            }
        }
    }
    cout << -1 << endl;
    return;
}
void Solve() {
    BFS();
}
int main() {
    getInput();
    Solve();
    return 0;
}