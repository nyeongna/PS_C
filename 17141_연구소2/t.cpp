#include <bits/stdc++.h>
using namespace std;

int graph[51][51];
int visit[51][51];
int n, m;
int ans = 2147000000;
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

int virus_num;

vector<pair<int, int>> vec;
vector<pair<int, int>> list_v(12);

void getInput()
{
    cin >> n >> m;
    int i, j;
    vec.push_back({0, 0});
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                graph[i][j] = 0;
                vec.push_back({i, j});
                virus_num++;
            }
        }
    }
}

typedef struct State
{
    int x, y, dist;
} State;

int BloodFill()
{
    memset(visit, 0, sizeof(visit));
    queue<State> Q;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        int f = list_v[i].first;
        int s = list_v[i].second;
        Q.push({f, s, 0});
        visit[f][s] = 1;
    }

    int max_time = -2147000000;
    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        Q.pop();
        max_time = max(max_time, dist);

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && graph[dx][dy] == 0 && visit[dx][dy] == 0)
            {
                visit[dx][dy] = dist + 1;
                Q.push({dx, dy, dist + 1});
            }
            
        }
    }

    //PrintVisit();

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (visit[i][j] == 0 && graph[i][j] == 0)
            {
                return 2147000000;
            }
        }
    }
    return max_time;
}

void DFS(int s, int level)
{
    if (level == m + 1)
    {
        int i, j;

        for (i = 1; i <= m; i++)
        {
            int x = list_v[i].first;
            int y = list_v[i].second;
            graph[x][y] = 2;
        }

        int time = BloodFill();
        ans = min(ans, time);

        for (i = 1; i <= m; i++)
        {
            int x = list_v[i].first;
            int y = list_v[i].second;
            graph[x][y] = 0;
        }
        return;
    }

    int i;

    for (i = s; i <= virus_num; i++)
    {
        list_v[level].first = vec[i].first;
        list_v[level].second = vec[i].second;
        DFS(i + 1, level + 1);
    }
}

void Solve()
{
    DFS(1, 1);
    if (ans == 2147000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    getInput();
    Solve();
    return 0;
}