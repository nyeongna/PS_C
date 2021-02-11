#include <bits/stdc++.h>
using namespace std;

char graph[501][501];

int r, c;

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
vector<pair<int, int>> W;
vector<pair<int, int>> S;

void getInput()
{
    int i, j;
    cin >> r >> c;
    string one_line;
    for (i = 1; i <= r; i++)
    {
        cin >> one_line;
        for (j = 0; j < one_line.size(); j++)
        {
            graph[i][j + 1] = one_line[j];
            if (graph[i][j + 1] == 'W')
            {
                W.push_back({i, j + 1});
            }
            if (graph[i][j + 1] == 'S')
            {
                S.push_back({i, j + 1});
            }
        }
    }
}

int canChase()
{
    int i, j;
    for (i = 0; i < W.size(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            int dx = W[i].first + x_dir[j];
            int dy = W[i].second + y_dir[j];
            if (dx >= 1 && dx <= r && dy >= 1 && dy <= c && graph[dx][dy] == 'S')
            {
                return 1;
            }
        }
    }
    return 0;
}

void buildFence()
{
    int i, j;
    for (i = 0; i < S.size(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            int dx = S[i].first + x_dir[j];
            int dy = S[i].second + y_dir[j];
            if (dx >= 1 && dx <= r && dy >= 1 && dy <= c && graph[dx][dy] == '.')
            {
                graph[dx][dy] = 'D';
            }
        }
    }
}

void Print()
{
    int i, j;
    cout << 1 << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

// 늑대 바로 인접칸에 양이 없으면 무조건 울타리 치기 가능
// 1. 늑대들 바로 인접칸에 양이 있나 없나 확인
// 2. 없다면 모든 양에 대하여 동서남북 울타리 쳐주면 끝.

int main()
{
    getInput();
    if (canChase() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    buildFence();
    Print();
    return 0;
}