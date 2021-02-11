#include <bits/stdc++.h>
using namespace std;


int graph[1001][1001];
int cache[1001][1001][2];
int m,n;
int hx, hy;
int ex, ey;

int x_dir[] = {-1,0,1,0};
int y_dir[] = {0,1,0,-1};

void getInput() {
    cin >> m >> n;
    cin >> hx >> hy;
    cin >> ex >> ey;
    int i,j;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            cin >> graph[i][j];
        }
    }
}

typedef struct State {
    int x, y, dist, block;
} State;

int BFS() {
    queue<State> Q;
    Q.push({hx, hy, 1, 1});
    cache[hx][hy][1] = 1;
    int i;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        int block = Q.front().block;
        Q.pop();

        if (x==ex && y==ey) {
            return dist-1;
        }

        for(i=0; i< 4; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx>=1 && dx<=m && dy>=1 && dy<=n) {
                // "벽칸으로 가고" + "벽 부술 수 있고" + "한번도 안간 벽이면"
                if (graph[dx][dy]==1 && block==1 && cache[dx][dy][block-1]==0) {
                    cache[dx][dy][block-1] = cache[x][y][block] + 1;
                    Q.push({dx,dy,dist+1,block-1});
                }
                // "빈칸으로 가고" + "벽 부술수 있거나/없거나" + "한번도 안간 벽이면"
                if (graph[dx][dy]==0 && cache[dx][dy][block]==0) {
                    cache[dx][dy][block] = cache[x][y][block] + 1;
                    Q.push({dx,dy,dist+1,block});
                }
            }
        }
    }
    return -1;
}

void Solve() {
    cout << BFS();
}
int main() {

    getInput();
    Solve();
    return 0;
}