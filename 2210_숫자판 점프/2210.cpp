#include <bits/stdc++.h>
using namespace std;

int graph[6][6];
int cnt = 0;
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
int visit[999999];

vector<int> V;

void getInput()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void DFS(int x, int y, int level, int value)
{
    if (level == 6)
    {
        if (visit[value] == 0)
        {
            visit[value] = 1;
            cnt++;
            V.push_back(value);
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++)
    {
        int dx = x + x_dir[i];
        int dy = y + y_dir[i];
        if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 5)
        {
            DFS(dx, dy, level + 1, value * 10 + graph[dx][dy]);
        }
    }
}
int main()
{
    getInput();
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            DFS(i, j, 1, graph[i][j]);
        }
    }
    cout << cnt << endl;
    return 0;
}