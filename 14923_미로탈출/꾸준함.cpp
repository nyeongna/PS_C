#include <bits/stdc++.h>
using namespace std;

int m, n;
int hx, hy;
int ex, ey;

// cache[x][y][0] : �� �ѹ� �μ��� �� �Ÿ�
// cache[x][y][1] : �� �ѹ��� �� �μ��� �� �Ÿ�
// cache[x][y][0]�� 0�� �ƴϸ� �̹� �� �� �μ��� �ּҰŸ��� �Դ� ��
// cache[x][y][1]�� 0�� �ƴϸ� �̹� �ѹ��� �Ⱥμ��� �ּҰŸ��� �Դ� ��

/*
https://jaimemin.tistory.com/695
*/

int graph[1001][1001];
int cache[1001][1001][2];

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};

void getInput()
{
    cin >> m >> n;
    cin >> hx >> hy;
    cin >> ex >> ey;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void BFS()
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{hx, hy}, 1});
    cache[hx][hy][1] = 1;
    int i;

    while (!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int block = Q.front().second;
        Q.pop();

        if (x == ex && y == ey)
        {
            cout << cache[x][y][block] - 1 << endl;
            return;
        }

        for (i = 0; i < 4; i++)
        {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];

            // ���� ����� �ߴٸ�
            if (dx >= 1 && dx <= m && dy >= 1 && dy <= n)
            {
                // "�� ĭ���� ����" + "�� �μ� �� �ְ�" + "�ѹ��� �� �μ� ��" �̸�
                if (graph[dx][dy] == 1 && block == 1 && cache[dx][dy][block - 1] == 0)
                {
                    // ������ �� ĭ�� (�μ��� + ���±��� �� �Ÿ�) + 1
                    cache[dx][dy][block - 1] = cache[x][y][block] + 1;
                    Q.push({{dx, dy}, 0});
                }

                // "�� ĭ���� ����" + "�ѹ��� �� �� ĭ" �̸�
                else if (graph[dx][dy] == 0 && cache[dx][dy][block] == 0)
                {
                    cache[dx][dy][block] = cache[x][y][block] + 1;
                    Q.push({{dx, dy}, block});
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

void Solve()
{
    BFS();
}

int main()
{
    getInput();
    Solve();
    return 0;
}