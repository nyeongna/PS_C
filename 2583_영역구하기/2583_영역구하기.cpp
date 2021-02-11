#include <bits/stdc++.h>
using namespace std;
int m, n, k;

int graph[120][120];
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
int cnt = 0;
int cnt2 = 0;

void DFS(int x, int y)
{
    for (int i = 0; i <= 4; i++)
    {
        int dx = x + x_dir[i];
        int dy = y + y_dir[i];
        if (dx >= 0 && dx < m && dy >= 0 && dy < n && graph[dx][dy] == 0)
        {
            cnt++;
            graph[dx][dy] = 1;
            DFS(dx, dy);
        }
    }
}

int main()
{
    cin >> m >> n >> k;
    int i, j, x, y;
    int lb_x, lb_y, rt_x, rt_y;

    for (i = 1; i <= k; i++)
    {
        cin >> lb_x >> lb_y >> rt_x >> rt_y;
        for (x = lb_y; x < rt_y; x++)
        {
            for (y = lb_x; y < rt_x; y++)
            {
                graph[x][y] = 1;
            }
        }
    }

    // 영역 크기를 저장할 벡터
    vector<int> a;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cnt = 0;
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                cnt++;
                DFS(i, j);
                a.push_back(cnt);
            }
        }
    }

    // 순서대로 정렬
    sort(a.begin(), a.end());

    // 사이즈 출력
    cout << a.size() << endl;

    //영역 크기 차례대로 출력
    for (i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}