#include <bits/stdc++.h>
using namespace std;

int m, n;
int rx, ry, rd;
int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

int graph[51][51];
int visit[51][51];

int cnt;

void getInput()
{
    cin >> m >> n;
    cin >> rx >> ry >> rd;
    rx = rx + 1;
    ry = ry + 1;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
}

int turnLeft(int dir)
{
    return (dir + 3) % 4;
}

int canTurn(int dir)
{
    if (graph[rx + x_dir[dir]][ry + y_dir[dir]] == 0 && visit[rx + x_dir[dir]][ry + y_dir[dir]] == 0)
        return 1;
    return 0;
}

int turnBack(int dir)
{
    return (dir + 2) % 4;
}

int canReverse(int dir)
{
    int dx = rx + x_dir[dir];
    int dy = ry + y_dir[dir];
    if (graph[dx][dy] == 0)
        return 1;
    else
        return 0;
}

void Solve()
{
    int i, j, nextDir, backDir, flag;

    while (1)
    {
        // 현재 위치를 청소한다.
        visit[rx][ry] = 1;
        cnt++;
        flag = 0;
        //cout << rx-1 << " " <<ry-1 << " " <<rd << endl;

        // 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 탐색을 시작.
        nextDir = rd;
        for (i = 0; i < 4; i++)
        {
            nextDir = turnLeft(nextDir);
            if (canTurn(nextDir) == 1)
            {
                rx = rx + x_dir[nextDir];
                ry = ry + y_dir[nextDir];
                rd = nextDir;
                flag = 1;
                break;
            }
        }

        // flag가 0이면 전진 불가란 뜻.
        if (flag == 0)
        {
            // 네 방향 모두 불가능하면 방향 유지하고 뒤로 1칸 후진.
            // 후진은 무조건 이미 방문한 곳으로 하므로 cnt-- 해준다.!
            backDir = turnBack(rd);
            if (canReverse(backDir) == 1)
            {
                rx = rx + x_dir[backDir];
                ry = ry + y_dir[backDir];
                cnt--;
            }

            // 후진 불가능하면 작동 멈춤.
            else
                break;
        }
    }

    cout << cnt << endl;
}

int main()
{
    getInput();
    Solve();
    return 0;
}