#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[51][51];
int visit[51][51];
vector<pair<int, int>> virus_list;
vector<pair<int, int>> v_set(11);
int virus_num;

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

void printGraph()
{
    int i, j;
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void printVisit()
{
    int i, j;
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < +n; j++)
        {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
}

void getInput()
{
    cin >> n >> m;
    int i, j;
    virus_list.push_back({0, 0});

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                graph[i][j] = 3;
                virus_list.push_back({i, j});
                virus_num++;
            }
        }
    }

    //printGraph();
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
        Q.push({v_set[i].first, v_set[i].second, 0});
    }

    int max_time = 0;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        Q.pop();

        if (graph[x][y] != 3)
        {
            max_time = max(max_time, dist);
        }

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && (graph[dx][dy] == 0 || graph[dx][dy] == 3) && visit[dx][dy] == 0)
            {
                visit[dx][dy] = dist + 1;
                Q.push({dx, dy, dist + 1});
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (graph[i][j] == 0 && visit[i][j] == 0)
            {
                return 2147000000;
            }
        }
    }

    return max_time;
}

int ans = 2147000000;

void DFS(int s, int level)
{
    int i, j;
    if (level == m + 1)
    {
        // for(i=1; i<=m; i++) {
        //     cout << v_set[i].first << " " << v_set[i].second << endl;
        // }
        // cout << endl;
        for (i = 1; i <= m; i++)
        {
            int f = v_set[i].first;
            int s = v_set[i].second;
            graph[f][s] = 2;
        }

        int time = BloodFill();
        ans = min(ans, time);

        for (i = 1; i <= m; i++)
        {
            int f = v_set[i].first;
            int s = v_set[i].second;
            graph[f][s] = 3;
        }

        return;
    }
    for (i = s; i <= virus_num; i++)
    {
        v_set[level].first = virus_list[i].first;
        v_set[level].second = virus_list[i].second;
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
    getInput();
    Solve();
    return 0;
}