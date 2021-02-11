#include <bits/stdc++.h>
using namespace std;

char graph[11][11];
int visit[11][11][11][11];
int n, m;

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
typedef struct Bead
{
    int rx, ry, bx, by, dist;
    Bead(int a, int b, int c, int d, int e)
    {
        rx = a;
        ry = b;
        bx = c;
        by = d;
        dist = e;
    }
} Bead;

Bead bead(0, 0, 0, 0, 0);

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
                bead.rx = i;
                bead.ry = j;
            }
            if (graph[i][j] == 'B')
            {
                bead.bx = i;
                bead.by = j;
            }
        }
    }
}
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
    Q.push(bead);
    visit[bead.rx][bead.ry][bead.bx][bead.by] = 1;
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

            // 파란공이 구멍에 빠졌을 때
            if (graph[n_bx][n_by] == 'O')
                continue;

            // 똑같은 곳에 떨어지면 더 멀리 굴러간 돌을 한칸 뒤로 뺀다.
            if ((n_rx == n_bx) && (n_ry == n_by))
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

            // 빨간 공이 구멍에 떨어지면 끝.
            if (graph[n_rx][n_ry] == 'O')
            {
                cout << dist + 1 << endl;
                return;
            }

            // 굴러가서 아무일도 없으면 queue에 추가한다.
            if (visit[n_rx][n_ry][n_bx][n_by] == 0)
            {
                visit[n_rx][n_ry][n_bx][n_by] = 1;
                Q.push(Bead(n_rx, n_ry, n_bx, n_by, dist + 1));
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