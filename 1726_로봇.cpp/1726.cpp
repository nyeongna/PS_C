#include <bits/stdc++.h>
using namespace std;

int m, n;
int graph[120][120];
int visit[120][120][5];
int x_dir[] = {0, 0, 0, 1, -1};
int y_dir[] = {0, 1, -1, 0, 0};
int sx, sy, sd;
int ex, ey, ed;

typedef struct State
{
    int x, y, dist, dir;
} State;

int BFS()
{
    queue<State> Q;
    Q.push({sx, sy, 0, sd});
    visit[sx][sy][sd] = 1;
    int i, j;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        int dir = Q.front().dir;
        Q.pop();

        //cout <<x<<y<<dir<<dist<<endl;

        if (x == ex && y == ey && dir == ed)
        {
            return dist;
        }

        // 전진 1 , 2, 3칸
        for (i = 1; i <= 3; i++)
        {
            int dx = x + x_dir[dir] * i;
            int dy = y + y_dir[dir] * i;

            // 여기가 키 포인트다! visir[dx][dy][dir]가 이미 방문했어도 그 다음칸을 검사해야만한다.

            if (visit[dx][dy][dir] != 0)
                continue;

            if (dx >= 1 && dx <= m && dy >= 1 && dy <= n && !graph[dx][dy])
            {
                visit[dx][dy][dir] = 1;
                Q.push({dx, dy, dist + 1, dir});
            }
            else
                break;
        }

        // 방향전환 1, 2, 3, 4
        for (i = 1; i <= 4; i++)
        {
            if (dir != i && visit[x][y][i] == 0)
            {
                visit[x][y][i] = 1;
                if ((dir == 1 && i == 2) || (dir == 2 && i == 1) || (dir == 3 && i == 4) || (dir == 4 && i == 3))
                {
                    Q.push({x, y, dist + 2, i});
                }
                else
                    Q.push({x, y, dist + 1, i});
            }
        }
    }

    return -1;
}

void getInput()
{
    cin >> m >> n;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;
}
int main()
{
    getInput();
    cout << BFS() << endl;
    return 0;
}