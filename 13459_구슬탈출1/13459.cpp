#include <bits/stdc++.h>
using namespace std;

int m, n;
char graph[11][11];
int visit[11][11][11][11];
int rx, ry, bx, by, gx, gy;
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

typedef struct Bead
{
    int rx, ry, bx, by, dist;
} Bead;

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

        // 기울인 횟수가 10 이상이면 break;
        if (dist >= 10)
        {
            break;
        }

        for (i = 0; i < 4; i++)
        {

            int nrx = rx, nry = ry, nbx = bx, nby = by, dist_r = 0, dist_b = 0;

            move(nrx, nry, x_dir[i], y_dir[i], dist_r);
            move(nbx, nby, x_dir[i], y_dir[i], dist_b);

            // 파란색 공이 구멍에 떨어지면 continue
            if (nbx == gx && nby == gy)
                continue;

            // 빨간색 공이 구멍에 떨어지면 끝
            if (nrx == gx && nry == gy)
            {
                cout << 1 << endl;
                return;
            }

            // 빨간색 파란색이 구멍에 안 떨어지고 겹쳤으면
            if (nrx == nbx && nry == nby)
            {
                if (dist_r > dist_b)
                {
                    nrx = nrx - x_dir[i];
                    nry = nry - y_dir[i];
                }
                else
                {
                    nbx = nbx - x_dir[i];
                    nby = nby - y_dir[i];
                }
            }

            if (visit[nrx][nry][nbx][nby] == 0)
            {
                visit[nrx][nry][nbx][nby] = 1;
                Q.push({nrx, nry, nbx, nby, dist + 1});
            }
        }
    }

    //여기 도달했다는건 빨간공이 어떠한 경우에도 구멍에 도달할 수 없는 경우.
    cout << 0 << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    getInput();
    BFS();
}