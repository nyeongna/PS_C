#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int graph[51][51];
int tmp[51][51];
int ux, uy;
int dx, dy;
int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

void AirconLoc()
{
    int i, j;
    for (i = 1; i <= r; i++)
    {
        if (graph[i][1] == -1)
        {
            ux = i;
            uy = 1;
            dx = i + 1;
            dy = 1;
            return;
        }
    }
}

void getInput()
{
    cin >> r >> c >> t;
    int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cin >> graph[i][j];
        }
    }
    AirconLoc();
}

void Spread()
{
    int i, j, k;
    memset(tmp, 0, sizeof(tmp));
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            // 해당 칸에 미세먼지가 있으면
            if (graph[i][j] >= 1)
            {
                // 4방향 검사
                int cnt = 0;
                for (k = 0; k < 4; k++)
                {
                    int dx = i + x_dir[k];
                    int dy = j + y_dir[k];

                    // 칸이 있고 공기청정기가 없다면 확산
                    if (dx >= 1 && dx <= r && dy >= 1 && dy <= c && graph[dx][dy] != -1)
                    {
                        tmp[dx][dy] = tmp[dx][dy] + graph[i][j] / 5;
                        cnt++;
                    }
                }
                graph[i][j] = graph[i][j] - graph[i][j] / 5 * cnt;
            }
        }
    }
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            graph[i][j] = graph[i][j] + tmp[i][j];
        }
    }
    return;
}

void Clean()
{
    int i, j, k;
    //ux:3 uy:1, dx:4, dy:1

    for (i = ux - 1; i >= 2; i--)
    {
        if (i == ux - 1)
            graph[i][1] = 0;
        else
            graph[i + 1][1] = graph[i][1];
    }

    for (j = 1; j <= c - 1; j++)
    {
        if (j == 1)
            graph[2][j] = graph[1][j];
        else
            graph[1][j - 1] = graph[1][j];
    }

    for (i = 1; i <= ux; i++)
    {
        if (i == 1)
            graph[1][c - 1] = graph[1][c];
        else
            graph[i - 1][c] = graph[i][c];
    }

    for (j = c; j >= 1; j--)
    {
        if (j == 1)
            graph[ux][j + 1] = 0;
        else if (j == c)
            graph[ux - 1][c] = graph[ux][c];
        else
            graph[ux][j + 1] = graph[ux][j];
    }

    //down

    for (i = dx + 1; i <= r - 1; i++)
    {
        if (i == dx + 1)
            graph[i][1] = 0;
        else
            graph[i - 1][1] = graph[i][1];
    }

    for (j = 1; j <= c - 1; j++)
    {
        if (j == 1)
            graph[r - 1][1] = graph[r][1];
        else
            graph[r][j - 1] = graph[r][j];
    }

    for (i = r; i >= dx + 1; i--)
    {
        if (i == r)
            graph[r][c - 1] = graph[r][c];
        else
            graph[i + 1][c] = graph[i][c];
    }

    for (j = c; j >= 1; j--)
    {
        if (j == 1)
            graph[dx][j + 1] = 0;
        else if (j == c)
            graph[dx + 1][c] = graph[dx][c];
        else
            graph[dx][j + 1] = graph[dx][j];
    }
}
void Print()
{
    int i, j;
    cout << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << ux << uy << dx << dy;
    cout << endl;
}

int Count()
{
    int i, j, total = 0;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (graph[i][j] > 0)
            {
                total = total + graph[i][j];
            }
        }
    }
    return total;
}
void Solve()
{
    int i, j, k;
    while (t != 0)
    {
        t--;
        Spread();
        Clean();
    }
    cout << Count();
}
int main()
{
    getInput();
    Solve();
    return 0;
}