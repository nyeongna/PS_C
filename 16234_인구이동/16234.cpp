#include <bits/stdc++.h>
using namespace std;

int graph[51][51];
int visit[51][51];
int visit_2[51][51];
int n, L, R;

void getInput()
{
    cin >> n >> L >> R;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
}

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

typedef struct State
{
    int x, y, num;
} State;

void Print()
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

int BFS(int x, int y)
{
    queue<State> Q;
    Q.push({x, y, graph[x][y]});
    visit[x][y] = 1;

    int i, total = graph[x][y];

    // 연합나라들 저장할 벡터
    // 나중에 인구이동 업데이트 할 때 쓰인다.
    vector<pair<int, int>> alliance;
    alliance.push_back({x, y});

    int flag = 0;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int num = Q.front().num;
        Q.pop();

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];

            if (dx >= 1 && dx <= n && dy >= 1 && dy <= n)
            {
                int gap = abs(graph[x][y] - graph[dx][dy]);

                // 한 번도 방문 안 한 나라들만 검사한다
                if (gap >= L && gap <= R && visit[dx][dy] == 0)
                {
                    visit[dx][dy] = 1;
                    total = total + graph[dx][dy];
                    Q.push({dx, dy, graph[dx][dy]});
                    alliance.push_back({dx, dy});

                    flag = 1;
                }
            }
        }
    }

    for (i = 0; i < alliance.size(); i++)
    {
        int x = alliance[i].first;
        int y = alliance[i].second;
        graph[x][y] = total / alliance.size();
    }

    return flag;
}

void Solve()
{

    int i, j, ans = 0, result;
    while (1)
    {
        result = 0;
        memset(visit, 0, sizeof(visit));

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (visit[i][j] == 0)
                {
                    // 단 한번이라도 인구이동 생기면 result=1로 초기화됨.
                    result = max(result, BFS(i, j));
                }
            }
        }

        // 인구이동이 없었다면 끝낸다.
        if (result == 0)
        {
            cout << ans << endl;
            return;
        }

        //인구이동이 있었으면 ans++ 한다.
        else if (result == 1)
        {
            ans++;
        }
    }
}

int main()
{
    getInput();
    Solve();
    return 0;
}