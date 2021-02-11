#include <bits/stdc++.h>
using namespace std;

int n;
int graph[2200][2200];
int cnt[6];

void getInput()
{
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
}

int Same(int n, int x, int y)
{
    int minus = 1;
    int zero = 1;
    int one = 1;
    int i, j;
    for (i = x; i <= x + n - 1; i++)
    {
        for (j = y; j <= y + n - 1; j++)
        {
            if (graph[i][j] == -1)
            {
                zero = 0;
                one = 0;
            }
            if (graph[i][j] == 0)
            {
                minus = 0;
                one = 0;
            }
            if (graph[i][j] == 1)
            {
                minus = 0;
                zero = 0;
            }
        }
    }
    if (minus == 1)
        return 1;
    if (zero == 1)
        return 2;
    if (one == 1)
        return 3;
    return 0;
}

void Divide(int n, int x, int y)
{
    int i, j;
    int abbr=n/3;

    if (n == 1)
    {
        cnt[graph[x][y] + 2]++;
        return;
    }

    if (Same(n, x, y))
    {
        cnt[graph[x][y]+2]++;
    }
    else
    {
        Divide(abbr, x, y);
        Divide(abbr, x, y + abbr);
        Divide(abbr, x, y + abbr + abbr);

        Divide(abbr, x + abbr, y);
        Divide(abbr, x + abbr, y + abbr);
        Divide(abbr, x + abbr, y + abbr + abbr);
 
        Divide(abbr, x + abbr + abbr, y);
        Divide(abbr, x + abbr + abbr, y + abbr);
        Divide(abbr, x + abbr + abbr, y + abbr + abbr);
    }
}

void Print()
{
    cout << cnt[1] << endl;
    cout << cnt[2] << endl;
    cout << cnt[3] << endl;
}

int main()
{
    getInput();
    Divide(n, 1, 1);
    Print();
    return 0;
}