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

        // �ٽ�! ��� �����ϴ� ����� ���� �����ϹǷ� pop�ǰ� �� �Ŀ� visit�� üũ�Ѵ�.
        visit[cur] = 1;

        // ans��  2147000000 ���� �ٲ���� �� ans���� ���� dist�� ����� �ʿ䰡 ����.
        if (ans < dist)
            break;

        // k�� ���� ������ �����ߴٸ� cnt++ ���ش�.
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