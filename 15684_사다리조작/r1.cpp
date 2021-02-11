#include <bits/stdc++.h>
using namespace std;

/*
    https://yabmoons.tistory.com/47
*/

int n, m, h;
int ladder[300][30];
int ans = 2147000000;

void Input()
{
    cin >> n >> m >> h;
    int i, j, x, y;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ladder[x][y] = 1;
    }
}

int ladderGame()
{
    int i, j, col, possible = 1;
    for (i = 1; i <= n; i++)
    {
        col = i;
        for (j = 1; j <= h; j++)
        {
            if (ladder[j][col])
                col++;
            else if (col >= 2 && ladder[j][col - 1])
                col--;
        }
        if (i != col)
        {
            possible = 0;
            return 0;
        }
    }
    return 1;
}

void Line(int idx, int cnt)
{
    if (cnt >= 4)
    {
        return;
    }
    if (ladderGame() == 1)
    {
        ans = min(ans, cnt);
        return;
    }
    int i, j;

    for (i = idx; i <= h; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (ladder[i][j - 1] == 1)
                continue;
            if (ladder[i][j + 1] == 1)
                continue;
            if (ladder[i][j] == 1)
                continue;

            ladder[i][j] = 1;
            Line(i, cnt + 1);
            ladder[i][j] = 0;
        }
    }
}

void Solve()
{

    Line(1, 0);

    if (ans == 2147000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}
