#include <bits/stdc++.h>
using namespace std;

int n, k;
int visit[100001];
int ans = 2147000000;
int cnt = 0;

void getInput()
{
    cin >> n >> k;
}

void BFS()
{
    queue<pair<int, int>> Q;
    Q.push({n, 0});
    visit[n] = 1;

    while (!Q.empty())
    {
        int cur = Q.front().first;
        int dist = Q.front().second;
        Q.pop();

        // 핵심! 모든 도달하는 경우의 수를 봐야하므로 pop되고 난 후에 visit를 체크한다.
        visit[cur] = 1;

        // ans가  2147000000 에서 바뀌었고 그 ans보다 높은 dist는 고려할 필요가 없다.
        if (ans < dist)
            break;

        // k가 같은 지점에 도달했다면 cnt++ 해준다.
        if (cur == k)
        {
            cnt++;
            ans = dist;
        }

        int next = cur + 1;
        if (next >= 0 && next <= 100000 && visit[next] == 0)
        {
            Q.push({next, dist + 1});
        }
        next = cur - 1;
        if (next >= 0 && next <= 100000 && visit[next] == 0)
        {
            Q.push({next, dist + 1});
        }
        next = cur * 2;
        if (next >= 1 && next <= 100000 && visit[next] == 0)
        {
            Q.push({next, dist + 1});
        }
    }

    cout << ans << endl;
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    getInput();
    BFS();
    return 0;
}