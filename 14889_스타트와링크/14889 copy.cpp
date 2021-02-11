#include <bits/stdc++.h>
using namespace std;

/*
    �ٽ� �˰��� ���� ����Ʈ
    https://sihyungyou.github.io/baekjoon-14889/
*/

int n;
int graph[30][30];
int visit[30];
int ans = 2147000000;

int list_start[30];
int list_link[30];

void DFS(int s, int level)
{
    int i, j;
    int start = 0, link = 0;
    if (level == n / 2)
    {
        int c = 1;
        int j, k;

        // start���� list_start�� ���ʴ�� ����Ǿ� �ְ�
        // start���� �ȵ� ���ڵ��� link���� �ִ´�.
        for (i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                list_link[c++] = i;
            }
        }

        // j=1 ~ n/2 ����, k = 1~n���� �ؼ�
        // ���� start���� �ش��ϴ� ����� �ٸ� ���� ������ (list_start[j], k) �� start�� �����ְ�
        // ���� link���� �ش��ϴ� ����� �ٸ� ���� ������ (list_link[j], k) �� link�� �����ش�.
        // �ٽ� �˰���!

        for (j = 1; j <= n / 2; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (list_start[j] != k && visit[k] == 1)
                {
                    start = start + graph[list_start[j]][k];
                }
                if (list_link[j] != k && visit[k] == 0)
                {
                    link = link + graph[list_link[j]][k];
                }
            }
        }
        // ���� �� ����� ���� �� ������ ���̰� ���� ���ٸ� ans�� ������Ʈ�Ѵ�.
        ans = min(ans, abs(start - link));
    }

    else
    {
        for (i = s; i <= n; i++)
        {
            visit[i] = 1;
            list_start[level + 1] = i;
            DFS(i + 1, level + 1);
            visit[i] = 0;
        }
    }
}

int main()
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
    DFS(1, 0);

    cout << ans << endl;
    return 0;
}