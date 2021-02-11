/*
    https://naivep.tistory.com/60
    ������ ���ؼ� ��� ������ ���ؼ� bfs�� ������ �ð��ʰ��� ����.
    ����,
    1) "�κ�"���� "������(1~n)" ������ �Ÿ��� ���ؼ� dy�� ������Ʈ
    2) "������"���� "������" ������ �Ÿ��� �����ؼ� dy�� ������Ʈ
    3) "������ ġ�췯 ���� ���� ����"�� ���ؼ� �ּڰ��� ���Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

char graph[21][21];
int visit[21][21];
int dy[11][11];
int m, n;
int rx, ry;

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

vector<pair<int, int>> dirty_list;
int dirty_num;

int rec[11];
int recVisit[11];
int ans = 2147000000;

void getInput()
{
    cin >> n >> m;
    if (n == 0 && m == 0)
        exit(0);
    int i, j;
    dirty_list.push_back({0, 0});
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == '*')
            {
                dirty_list.push_back({i, j});
                dirty_num++;
            }
            if (graph[i][j] == 'o')
            {
                rx = i;
                ry = j;
            }
        }
    }
}
typedef struct State
{
    int x, y, dist;
} State;

int BFS(int sx, int sy, int gx, int gy)
{
    memset(visit, 0, sizeof(visit));

    queue<State> Q;
    Q.push({sx, sy, 0});
    visit[sx][sy] = 1;
    int i;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        Q.pop();

        if (x == gx && y == gy)
        {
            return dist;
        }

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= m && dy >= 1 && dy <= n && graph[dx][dy] != 'x' && visit[dx][dy] == 0)
            {
                visit[dx][dy] = 1;
                Q.push({dx, dy, dist + 1});
            }
        }
    }
    return -1;
}

void Solve()
{
    int i, j;

    // �κ����� ������(1~n)������ �Ÿ����ؼ� dy�� ������Ʈ
    for (i = 1; i < dirty_list.size(); i++)
    {
        int gx = dirty_list[i].first;
        int gy = dirty_list[i].second;
        dy[0][i] = BFS(rx, ry, gx, gy);
        dy[i][0] = dy[0][i];
        if (dy[0][i] == -1)
        {
            ans = -1;
            return;
        }
    }

    // �����⿡�� ����������� �Ÿ� ���ؼ� dy�� ������Ʈ
    for (i = 1; i < dirty_list.size(); i++)
    {
        int sx = dirty_list[i].first;
        int sy = dirty_list[i].second;
        for (j = 1; j < dirty_list.size(); j++)
        {
            int gx = dirty_list[j].first;
            int gy = dirty_list[j].second;
            if (i == j)
                continue;
            if (dy[i][j] == 0)
            {
                dy[i][j] = BFS(sx, sy, gx, gy);
                dy[j][i] = dy[i][j];
            }
        }
    }

    // for (i = 0; i <= dirty_num; i++)
    // {
    //     for (j = 0; j <= dirty_num; j++)
    //     {
    //         cout << dy[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void DFS(int level)
{
    int i;
    if (level == dirty_num + 1)
    {
        int total = dy[0][rec[1]];
        for (i = 1; i < dirty_num; i++)
        {
            total = total + dy[rec[i]][rec[i + 1]];
        }

        ans = min(ans, total);
    }
    else
    {
        for (i = 1; i <= dirty_num; i++)
        {
            if (recVisit[i] == 0)
            {
                recVisit[i] = 1;
                rec[level] = i;
                DFS(level + 1);
                recVisit[i] = 0;
            }
        }
    }
}

void Reset()
{
    memset(visit, 0, sizeof(visit));
    memset(dy, 0, sizeof(dy));
    memset(rec, 0, sizeof(rec));
    memset(recVisit, 0, sizeof(recVisit));
    dirty_num = 0;
    ans = 2147000000;
    dirty_list.clear();
}
int main()
{
    while (1)
    {
        Reset();
        getInput();

        // dy �����
        Solve();

        // �������� �ּҰŸ� ã��.
        if (ans != -1)
            DFS(1);
        cout << ans << endl;
    }
    return 0;
}