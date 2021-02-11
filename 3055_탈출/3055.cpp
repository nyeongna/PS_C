#include <bits/stdc++.h>
using namespace std;

int r, c;
char graph[51][51];
int visit[51][51];

int hx, hy, bx, by;
vector<pair<int,int>> water;

void getInput()
{
    cin >> r >> c;
    int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cin >> graph[i][j];

            // 물이 여러 개 일수 있다. (즉 1개이상)
            if (graph[i][j] == '*')
            {
                water.push_back({i,j});
            }
            if (graph[i][j] == 'S')
            {
                hx = i;
                hy = j;
            }
            if (graph[i][j] == 'D')
            {
                bx = i;
                by = j;
            }
        }
    }
}

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

typedef struct State
{
    int x, y, dist, ch;
} State;

void BFS()
{
    int i;
    queue<State> Q;
    for(i=0; i<water.size(); i++) {
        Q.push({water[i].first, water[i].second, 0, 1});
        visit[water[i].first][water[i].second] = 1;
    }
    Q.push({hx, hy, 0, 2});
    visit[hx][hy] = 1;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dist;
        int ch = Q.front().ch;
        Q.pop();

        // cout << x << y << dist << ch << endl;
        // cout << graph[x][y] << ch << endl;
        if (graph[x][y] == 'D' && ch == 2)
        {
            cout << dist << endl;
            return;
        }

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            //cout << "dx: " <<dx << " " <<"dy: "<<dy <<endl;
            //cout << c << dx << dy << graph[dx][dy] << visit[dx][dy] << endl;
            if (ch ==1 && dx >= 1 && dx <= r && dy >= 1 && dy <= c && graph[dx][dy] == '.' && visit[dx][dy] == 0)
            {
                visit[dx][dy] = 1;
                Q.push({dx, dy, dist + 1, ch});
                //cout <<"pushed "<< dx << " " << dy << " " << dist + 1 <<" "<< ch << endl;
            }
            if (ch == 2 && dx >= 1 && dx <= r && dy >= 1 && dy <= c && (graph[dx][dy] == '.' || graph[dx][dy] == 'D') && visit[dx][dy] == 0)
            {
                visit[dx][dy] = 1;
                Q.push({dx, dy, dist + 1, ch});
                //cout << "pushed " <<dx << " " << dy << " " << dist + 1 <<" "<< ch << endl;
            }
        }
    }

    cout << "KAKTUS" << endl;
    return;
}

void Solve()
{
    BFS();
}

int main()
{
    getInput();
    Solve();

    return 0;
}