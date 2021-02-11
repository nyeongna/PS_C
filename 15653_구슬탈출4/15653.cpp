#include <bits/stdc++.h>
using namespace std;

#define MAX 11

int m, n;
char graph[MAX][MAX];
int visit[MAX][MAX][MAX][MAX];
int rx, ry, bx, by, gx, gy;

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

void getInput()
{
    cin >> m >> n;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            if (graph[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
            if (graph[i][j] == 'O')
            {
                gx = i;
                gy = j;
            }
        }
    }
}

typedef struct Bead
{
    int rx, ry, bx, by, dist;
} Bead;

void move(int &x, int &y, int dx, int dy, int &dist)
{
    while (graph[x + dx][y + dy] != '#' && graph[x][y] != 'O')
    {
        x = x + dx;
        y = y + dy;
        dist = dist + 1;
    }
}
void BFS()
{
    queue<Bead> Q;
    Q.push({rx, ry, bx, by, 0});
    visit[rx][ry][bx][by] = 1;
    int i;

    while (!Q.empty())
    {
        int rx = Q.front().rx;
        int ry = Q.front().ry;
        int bx = Q.front().bx;
        int by = Q.front().by;
        int dist = Q.front().dist;
        Q.pop();

        for (i = 0; i < 4; i++)
        {
            int n_rx = rx;
            int n_ry = ry;
            int n_bx = bx;
            int n_by = by;
            int dist_r = 0, dist_b = 0;
            move(n_rx, n_ry, x_dir[i], y_dir[i], dist_r);
            move(n_bx, n_by, x_dir[i], y_dir[i], dist_b);

            // 파란색이 구멍에 빠졌을 때
            if (n_bx == gx && n_by == gy)
            {
                continue;
            }

            // 빨간색이 구멍에 빠졌을 때
            if (n_rx == gx && n_ry == gy)
            {
                cout << dist + 1 << endl;
                exit(0);
            }

            // 빨간색, 파란색이 겹쳐있는 경우
            if (n_rx == n_bx && n_ry == n_by)
            {
                if (dist_r > dist_b)
                {
                    n_rx = n_rx - x_dir[i];
                    n_ry = n_ry - y_dir[i];
                }
                else
                {
                    n_bx = n_bx - x_dir[i];
                    n_by = n_by - y_dir[i];
                }
            }

            if (visit[n_rx][n_ry][n_bx][n_by] == 0)
            {
                visit[n_rx][n_ry][n_bx][n_by] = 1;
                Q.push({n_rx, n_ry, n_bx, n_by, dist + 1});
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    getInput();
    BFS();

    return 0;
}