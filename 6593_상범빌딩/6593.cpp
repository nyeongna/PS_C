#include <bits/stdc++.h>
using namespace std;

int l, r, c;
char graph[32][32][32];
int visit[32][32][32];
int x_dir[6] = {0, 0, 0, 0, 1, -1};
int y_dir[6] = {-1, 0, 1, 0, 0, 0};
int z_dir[6] = {0, 1, 0, -1, 0, 0};

typedef struct Pos
{
    int level, row, col;
    Pos(int a, int b, int c)
    {
        level = a;
        row = b;
        col = c;
    }
} Pos;

Pos start(0, 0, 0);
Pos goal(0, 0, 0);

void Init()
{
    memset(visit, 0, sizeof(visit));
}

void printGraph()
{
    int i, j, k;
    for (i = 1; i <= l; i++)
    {
        for (j = 1; j <= r; j++)
        {
            for (k = 1; k <= c; k++)
            {
                cout << graph[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void printVisit()
{
    int i, j, k;
    for (i = 1; i <= l; i++)
    {
        for (j = 1; j <= r; j++)
        {
            for (k = 1; k <= c; k++)
            {
                cout << visit[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void getInput()
{
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0)
        exit(0);

    int i, j, k;
    for (i = 1; i <= l; i++)
    {
        for (j = 1; j <= r; j++)
        {
            for (k = 1; k <= c; k++)
            {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 'S')
                {
                    start.level = i;
                    start.row = j;
                    start.col = k;
                }
                if (graph[i][j][k] == 'E')
                {
                    goal.level = i;
                    goal.row = j;
                    goal.col = k;
                }
            }
        }
    }
    // printGraph();
    // cout << start.level << start.row << start.col <<endl;
    // cout << goal.level << goal.row << goal.col <<endl;
}
void Solve()
{
    queue<Pos> Q;
    Q.push(Pos(start.level, start.row, start.col));
    visit[start.level][start.row][start.col] = 1;

    while (!Q.empty())
    {
        Pos tmp = Q.front();
        int level = tmp.level;
        int row = tmp.row;
        int col = tmp.col;
        Q.pop();
        int i;
        for (i = 0; i < 6; i++)
        {
            int dx = level + x_dir[i];
            int dy = row + y_dir[i];
            int dz = col + z_dir[i];
            if (dx >= 1 && dx <= l && dy >= 1 && dy <= r && dz >= 1 && dz <= c && visit[dx][dy][dz] == 0 && (graph[dx][dy][dz] == '.' || graph[dx][dy][dz] == 'E'))
            {
                visit[dx][dy][dz] = visit[level][row][col] + 1;
                Q.push(Pos(dx, dy, dz));
            }
        }
    }

    int ans = visit[goal.level][goal.row][goal.col];

    if (ans == 0)
    {
        cout << "Trapped!" << endl;
    }
    else
    {
        cout << "Escaped in " << ans - 1 << " minute(s)." << endl;
    }
}

int main()
{
    while (1)
    {
        Init();
        getInput();
        Solve();
    }
    return 0;
}