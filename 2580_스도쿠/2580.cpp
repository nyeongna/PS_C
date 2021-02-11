#include <bits/stdc++.h>
using namespace std;

int graph[10][10];
int row[10][10];
int col[10][10];
int square[10][10];
int cnt = 0;

void DFS(int count)
{
    int i, j;
    int dx, dy;
    if (count == cnt)
    {
        for (i = 1; i <= 9; i++)
        {
            for (j = 1; j <= 9; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    else
    {
        int flag = 0;
        for (i = 1; i <= 9; i++)
        {
            for (j = 1; j <= 9; j++)
            {
                if (graph[i][j] == 0)
                {
                    dx = i;
                    dy = j;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        //cout << "dx:" << dx << " " << "dy:" << dy << endl;
        for (i = 1; i <= 9; i++)
        {
            if (row[dx][i] == 0 && col[dy][i] == 0 && square[(dx - 1) / 3 * 3 + (dy - 1) / 3][i] == 0)
            {
                row[dx][i] = 1;
                col[dy][i] = 1;
                square[(dx - 1) / 3 * 3 + (dy - 1) / 3][i] = 1;
                graph[dx][dy] = i;

                DFS(count + 1);

                row[dx][i] = 0;
                col[dy][i] = 0;
                square[(dx - 1) / 3 * 3 + (dy - 1) / 3][i] = 0;
                graph[dx][dy] = 0;
            }
        }
    }
}

int main()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            cin >> graph[i][j];
            row[i][graph[i][j]] = 1;
            col[j][graph[i][j]] = 1;
            square[(i - 1) / 3 * 3 + (j - 1) / 3][graph[i][j]] = 1;
            if (graph[i][j] == 0)
                cnt++;
        }
    }

    DFS(0);

    return 0;
}