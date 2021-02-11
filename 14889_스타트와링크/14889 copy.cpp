#include <bits/stdc++.h>
using namespace std;

/*
    핵심 알고리즘 참고 사이트
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

        // start팀은 list_start에 차례대로 저장되어 있고
        // start팀에 안들어간 숫자들을 link팀에 넣는다.
        for (i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                list_link[c++] = i;
            }
        }

        // j=1 ~ n/2 까지, k = 1~n까지 해서
        // 현재 start팀에 해당하는 멤버면 다른 값을 가지는 (list_start[j], k) 를 start에 더해주고
        // 현재 link팀에 해당하는 멤버면 다른 값을 가지는 (list_link[j], k) 를 link에 더해준다.
        // 핵심 알고리즘!

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
        // 현재 팀 멤버로 나온 팀 전투력 차이가 가장 낮다면 ans에 업데이트한다.
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