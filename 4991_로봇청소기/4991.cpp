#include <bits/stdc++.h>
using namespace std;

char graph[21][21];
int visit[21][21];
int dy[11][11];
int m, n;
vector<pair<int, int>> dirty_list;
int dirty_cnt;

int sx, sy;
int rx, ry;

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

void getInput()
{
    cin >> n >> m;
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
                dirty_cnt++;
            }
            if (graph[i][j] == 'o')
            {
                graph[i][j] = '.';
                sx = i;
                sy = j;
                rx = i;
                ry = j;
            }
        }
    }
}

int rec[11];
int recVisit[11];

typedef struct State
{
    int x, y, dist;
} State;

int BFS(int from, int to)
{
    memset(visit, 0, sizeof(visit));
    queue<State> Q;
    int gx = dirty_list[to].first;
    int gy = dirty_list[to].second;
    Q.push({rx, ry, 0});
    visit[rx][ry] = 1;
    int i;

    if (dy[from][to]!=0) {
        rx = gx;
        ry = gy;
        return dy[from][to];
    }

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        Q.pop();

        if (x == gx && y == gy)
        {
            dy[from][to] = dist;
            rx = x;
            ry = y;
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

int ans = 2147000000;

void DFS(int level)
{
    int i;
    if (level == dirty_cnt + 1)
    {
        int dist, total = 0;
        rx = sx;
        ry = sy;
        for (i = 1; i <= dirty_cnt; i++)
        {
            dist = BFS(rec[i-1], rec[i]);
            if (dist==-1) {
                ans= -1;
                return;
            }
            total = total + dist;
        }
        // for (i = 1; i <= dirty_cnt; i++)
        // {
        //     cout << rec[i] << " ";
        // }
        // cout << ": " << total << endl;
        ans = min(ans, total);
    }
    else
    {

        for (i = 1; i <= dirty_cnt; i++)
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

void Reset() {
    memset(visit, 0, sizeof(visit));
    memset(graph, 0, sizeof(graph));
    memset(rec, 0, sizeof(rec));
    memset(recVisit, 0, sizeof(recVisit));
    memset(dy, 0, sizeof(dy));
    dirty_cnt=0;
    dirty_list.clear();
    ans = 2147000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    while (1)
    {
        Reset();
        getInput();
        if (m==0 && n==0) return 0;
        DFS(1);
        cout << ans << endl;
    }

    return 0;
}