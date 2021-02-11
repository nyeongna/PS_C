#include<iostream>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 101
using namespace std;
 
int M, N;
int MAP[MAX][MAX];
bool Visit[MAX][MAX][5];
 
int dx[] = { 0, 0, 0, 1, - 1 };
int dy[] = { 0, 1, -1, 0, 0 };
 
vector<pair<pair<int, int>, int >> Start, End;
 
void Input()
{
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    Start.push_back(make_pair(make_pair(a, b), c));
    cin >> a >> b >> c;
    End.push_back(make_pair(make_pair(a, b), c));
}
 
bool Can_Go(int x, int y, int d, int k)
{
    int nx = x + dx[d] * k;
    int ny = y + dy[d] * k;
 
    if (nx < 1 || ny < 1 || nx > M || ny > N) return false;
 
    nx = x;
    ny = y;
 
    for (int i = 0; i < k; i++)
    {
        nx = nx + dx[d];
        ny = ny + dy[d];
 
        if (MAP[nx][ny] == 1) return false;
    }
    return true;
}
 
int Change_Direction(int d, char c)
{
    if (c == 'L')
    {
        if (d == 1) return 4;
        else if (d == 2) return 3;
        else if (d == 3) return 1;
        else if (d == 4) return 2;
    }
    else if (c == 'R')
    {
        if (d == 1) return 3;
        else if (d == 2) return 4;
        else if (d == 3) return 2;
        else if (d == 4) return 1;
    }
}
 
void BFS(int a, int b, int c)
{
    queue < pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(c, 0)));
    Visit[a][b][c] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int d = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();

        cout <<x<<y<<d<<Cnt<<endl;
 
        if (x == End.front().first.first && y == End.front().first.second && d == End.front().second)
        {
            cout << Cnt << endl;
            return;
        }
 
        for (int i = 1; i <= 3; i++)
        {
            if (Can_Go(x, y, d, i) == true)
            {
                int nx = x + dx[d] * i;
                int ny = y + dy[d] * i;
 
                if (Visit[nx][ny][d] == false)
                {
                    Visit[nx][ny][d] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(d, Cnt + 1)));
                }
            }
        }
 
        int nd;
        nd = Change_Direction(d, 'L');
        if (Visit[x][y][nd] == false)
        {
            Visit[x][y][nd] = true;
            Q.push(make_pair(make_pair(x, y), make_pair(nd, Cnt + 1)));
        }
 
        nd = Change_Direction(d, 'R');
        if (Visit[x][y][nd] == false)
        {
            Visit[x][y][nd] = true;
            Q.push(make_pair(make_pair(x, y), make_pair(nd, Cnt + 1)));
        }
    }
}
 
void Solution()
{
    int x = Start.front().first.first;
    int y = Start.front().first.second;
    int d = Start.front().second;
    BFS(x, y, d);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


