#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

char board[1001][1001];
// dist[x][y][0] �� �Ⱥμ��� �� �ּҰŸ�
// dist[x][y][1] �� �μ��� �� �ּҰŸ�
int dist[1001][1001][2];
int x_dir[4] = { -1,0,1,0 };
int y_dir[4] = { 0,1,0,-1 };

int n, m;

struct Tile {
    int x, y, destroy, dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    queue<Tile> Q;
    Q.push({ 1,1,0,1});
    dist[1][1][0] = 1;
    dist[1][1][1] = 1;

    int ans = 2147000000;
    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int destroy = Q.front().destroy;
        int distance = Q.front().dist;
        Q.pop();
        //cout << x << " " << y << " " << destroy << endl;

        if (x == n && y == m) {
            ans = min(ans, distance);
        }

        int i;
        for (i = 0; i < 4; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
                int c = board[dx][dy]-48;

                //cout << dx << " " << dy << " " << destroy << " " << board[dx][dy]<<" " << dist[dx][dy][0]<<" " << dist[dx][dy][1] << endl;
                // ���� �Ⱥν��� �ѹ��� �� ���� 0/1���� �̵�
                if (destroy == 0 && dist[dx][dy][c] == 0) {
                    dist[dx][dy][c] = dist[x][y][0] + 1;
                    Q.push({ dx,dy,c, dist[dx][dy][c]});
                }
                // �ν���, �ѹ��� �� ���� 0���� �̵�
                if (destroy == 1 && board[dx][dy] == '0' && dist[dx][dy][1] == 0) {
                    dist[dx][dy][1] = dist[x][y][1] + 1;
                    Q.push({ dx,dy,1, dist[dx][dy][1]});
                }
            }
        }
    }
    if (ans==2147000000) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }




    return 0;
}