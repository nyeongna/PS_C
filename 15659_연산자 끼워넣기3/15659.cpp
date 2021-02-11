#include <bits/stdc++.h>
using namespace std;

int graph[12];
int operators[5];
int max_num = -2147000000;
int min_num = 2147000000;
int n;

void getInput()
{
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        cin >> graph[i];
    }
    for (i = 1; i <= 4; i++)
    {
        cin >> operators[i];
    }
}

void DFS(int num, int level)
{
    int i;
    if (level == n)
    {
        max_num = max(max_num, num);
        min_num = min(min_num, num);
        return;
    }
    else
    {
        if (operators[1] != 0)
        {
            operators[1]--;
            DFS(num + graph[level + 1], level + 1);
            operators[1]++;
        }
        if (operators[2] != 0)
        {
            operators[2]--;
            DFS(num - graph[level + 1], level + 1);
            operators[2]++;
        }
        if (operators[3] != 0)
        {
            operators[3]--;
            DFS(num * graph[level + 1], level + 1);
            operators[3]++;
        }
        if (operators[4] != 0)
        {
            operators[4]--;
            DFS(num / graph[level + 1], level + 1);
            operators[4]++;
        }
    }
}

void Solve()
{
    DFS(graph[1], 1);
    cout << max_num << endl;
    cout << min_num << endl;
}

int main()
{
    getInput();
    Solve();
    return 0;
}