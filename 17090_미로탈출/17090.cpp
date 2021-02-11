#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[501][501];
int dy[501][501];

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

// dy[i][j]¿¡´Â (i,j) À§Ä¡ÇÑ ÁÂÇ¥°¡
// 1. Å»Ãâ °¡´ÉÇÑ ÁÂÇ¥ÀÎÁö       1
// 2. Å»Ãâ ºÒ°¡´ÉÇÑ ÁÂÇ¥ÀÎÁö    -1
// 3. Å½»ö ¾ÈÇÑ °÷              0

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
}

int FindDir(int x, int y)
{
    if (graph[x][y] == 'U')
        return 0;
    if (graph[x][y] == 'R')
        return 1;
    if (graph[x][y] == 'D')
        return 2;
    if (graph[x][y] == 'L')
        return 3;
    return 4;
}

int DFS(int x, int y)
{
    if (x < 1 || x > m || y < 1 || y > n)
        return 1;
    if (dy[x][y] != 0)
        return dy[x][y];

    dy[x][y] = -1;

    int dir = FindDir(x, y);
    return dy[x][y] = DFS(x + x_dir[dir], y + y_dir[dir]);
}

void Solve()
{
    int i, j, cnt = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int a = DFS(i, j);
            if (a == 1)
                cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    getInput();
    Solve();
    return 0;
}