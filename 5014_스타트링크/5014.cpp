#include <bits/stdc++.h>
using namespace std;

int total, cur, target, U, D;
int visit[1000003];

void Solve()
{
    int i, j;
    queue<pair<int, int>> Q;
    Q.push({cur, 0});
    visit[cur] = 1;

    while (!Q.empty())
    {
        int now = Q.front().first;
        int level = Q.front().second;
        Q.pop();

        if (now == target)
        {
            cout << level;
            return;
        }

        if (now + U >= 1 && now + U <= total && visit[now + U] == 0)
        {
            visit[now + U] = 1;
            Q.push({now + U, level + 1});
        }

        if (now - D >= 1 && now - D <= total && visit[now - D] == 0)
        {
            visit[now - D] = 1;
            Q.push({now - D, level + 1});
        }
    }
    cout << "use the stairs";
}

int main()
{
    cin >> total >> cur >> target >> U >> D;
    Solve();
}