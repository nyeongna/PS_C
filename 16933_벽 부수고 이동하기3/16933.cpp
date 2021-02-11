#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

char board[1001][1001];
// dist[x][y][0] 은 안부수고 간 최소거리
// dist[x][y][1] 은 부수고 간 최소거리
int dist[1001][1001][11];
int x_dir[4] = { -1,0,1,0 };
int y_dir[4] = { 0,1,0,-1 };
int ans[11];

int n, m, k;

struct Tile {
    int x, y, destroy, dist, t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> k;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    queue<Tile> Q;
    Q.push({ 1,1,0,1, 1 });
    dist[1][1][0] = 1;

    int ans = 2147000000;
    int time = 1;
    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int destroy = Q.front().destroy;
        int distance = Q.front().dist;
        int t = Q.front().t;
        Q.pop();
        //cout << x << " " << y << " " << destroy << endl;

        if (x == n && y == m) {
            cout << distance << endl;
            return 0;
        }

        int i;
        for (i = 0; i < 4; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {

                int c = board[dx][dy] - 48;
                // ( 0 ~ k-1) 번 부쉈고, 한번도 안 가본 0/1 로 이동
                if (destroy < k && dist[dx][dy][destroy + c] == 0) {
                    dist[dx][dy][destroy + c] = dist[x][y][destroy] + 1;
                    Q.push({ dx,dy,destroy + c,dist[dx][dy][destroy + c] });
                }

                // k 번 부쉈고, 한번도 안 가본 0으로 이동
                if (destroy == k && board[dx][dy] == '0' && dist[dx][dy][destroy] == 0) {
                    dist[dx][dy][destroy] = dist[x][y][destroy] + 1;
                    Q.push({ dx,dy,destroy, dist[dx][dy][destroy] });
                }

            }
        }
    }
    return 0;
}