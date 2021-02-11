#include <bits/stdc++.h>
using namespace std;

/*
    �ѹ��� �۾����� ���� �� ��� �۾��� �����ϴ�! 
*/

int N, L;
int graph[101][101];
int visit[101][101][2];
int tmp[101][101][2];
int possible_route;

void getInput()
{
    cin >> N >> L;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
        }
    }
    possible_route = N * 2;
}

void rowOperation()

{
    int i, j, k;

    for (i = 1; i <= N; i++)
    {
        int flag = 1;
        memset(tmp, 0, sizeof(tmp));
        for (j = 1; j < N; j++)
        {
            // ���� ���̰� 2�̻� ���� �� ���� fail
            if (abs(graph[i][j + 1] - graph[i][j]) > 1)
            {
                possible_route--;
                break;
            }
            // �����ϴ� ������ 1 �� ���ٸ�
            else if (graph[i][j + 1] == graph[i][j] + 1)
            {

                // ���θ� ���� ������ "L" ���� �����ϸ� �� ���� fail
                if (j < L)
                {
                    possible_route--;
                    break;
                }

                // ���ΰ� L ������ŭ �̹� ������ �ִ��� �˻�
                for (k = j; k >= j - L + 1; k--)
                {
                    if (visit[i][k][0] == 1)
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }

                if (!flag)
                    break;

                // ���ΰ� ��� ���� �������� �˻�
                for (k = j; k > j - L + 1; k--)
                {
                    if (graph[i][k] != graph[i][k - 1])
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���θ� L ������ŭ ���´�.
                for (k = j; k >= j - L + 1; k--)
                {
                    visit[i][k][0] = 1;
                    tmp[i][k][0] = 1;
                }
            }

            // �����ϴ� ������ 1 �� ���ٸ�
            else if (graph[i][j + 1] == graph[i][j] - 1)
            {
                // ��縦 ���� ������ "L"���� �����ϸ� fail.
                if (N - j < L)
                {
                    possible_route--;
                    break;
                }

                // ���ΰ� L ������ŭ �̹� ������ �ִ��� �˻�
                for (k = j + 1; k <= j + L; k++)
                {
                    if (visit[i][k][0] == 1)
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���ΰ� ��� ���� �������� �˻�
                for (k = j + 1; k < j + L; k++)
                {
                    if (graph[i][k] != graph[i][k + 1])
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���θ� L ������ŭ ���´�.
                for (k = j + 1; k <= j + L; k++)
                {
                    visit[i][k][0] = 1;
                    tmp[i][k][0] = 1;
                }
            }
        }

        if (flag == 0)
        {
            for (int a = 1; a <= N; a++)
            {
                if (tmp[i][a][0] == 1)
                    visit[i][a][0] = 0;
            }
        }
    }
}
void colOperation()

{
    int i, j, k;

    for (i = 1; i <= N; i++)
    {
        int flag = 1;
        memset(tmp, 0, sizeof(tmp));
        for (j = 1; j < N; j++)
        {
            // ���� ���̰� 2�̻� ���� �� ���� fail
            if (abs(graph[j + 1][i] - graph[j][i]) > 1)
            {
                possible_route--;
                break;
            }
            // �����ϴ� ������ 1 �� ���ٸ�
            else if (graph[j + 1][i] == graph[j][i] + 1)
            {

                // ���θ� ���� ������ "L" ���� �����ϸ� �� ���� fail
                if (j < L)
                {
                    possible_route--;
                    break;
                }

                // ���ΰ� L ������ŭ �̹� ������ �ִ��� �˻�
                for (k = j; k >= j - L + 1; k--)
                {
                    if (visit[k][i][1] == 1)
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }

                if (!flag)
                    break;

                // ���ΰ� ��� ���� �������� �˻�
                for (k = j; k > j - L + 1; k--)
                {
                    if (graph[k][i] != graph[k - 1][i])
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���θ� L ������ŭ ���´�.
                for (k = j; k >= j - L + 1; k--)
                {
                    visit[k][i][1] = 1;
                    tmp[k][i][1] = 1;
                }
            }

            // �����ϴ� ������ 1 �� ���ٸ�
            else if (graph[j + 1][i] == graph[j][i] - 1)
            {
                // ��縦 ���� ������ "L"���� �����ϸ� fail.
                if (N - j < L)
                {
                    possible_route--;
                    break;
                }

                // ���ΰ� L ������ŭ �̹� ������ �ִ��� �˻�
                for (k = j + 1; k <= j + L; k++)
                {
                    if (visit[k][i][1] == 1)
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���ΰ� ��� ���� �������� �˻�
                for (k = j + 1; k < j + L; k++)
                {
                    if (graph[k][i] != graph[k + 1][i])
                    {
                        possible_route--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;

                // ���θ� L ������ŭ ���´�.
                for (k = j + 1; k <= j + L; k++)
                {
                    visit[k][i][1] = 1;
                    tmp[k][i][1] = 1;
                }
            }
        }
        if (flag == 0)
        {
            for (int a = 1; a <= N; a++)
            {
                if (tmp[a][i][1] == 1)
                    visit[a][i][1] = 0;
            }
        }
    }
}
void Print1()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cout << visit[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Print2()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cout << visit[i][j][1] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Solve()
{
    rowOperation();
    colOperation();
    cout << possible_route << endl;
}
int main()
{
    getInput();
    Solve();
    return 0;
}