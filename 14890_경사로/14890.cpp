#include <bits/stdc++.h>
using namespace std;

/*
    한번의 작업으로 열과 행 모두 작업이 가능하다! 
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
            // 높이 차이가 2이상 나면 이 길은 fail
            if (abs(graph[i][j + 1] - graph[i][j]) > 1)
            {
                possible_route--;
                break;
            }
            // 진행하는 방향이 1 더 높다면
            else if (graph[i][j + 1] == graph[i][j] + 1)
            {

                // 경사로를 놓을 공간이 "L" 보다 부족하면 이 길은 fail
                if (j < L)
                {
                    possible_route--;
                    break;
                }

                // 경사로가 L 공간만큼 이미 놓여져 있는지 검사
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

                // 경사로가 모두 같은 높이인지 검사
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

                // 경사로를 L 공간만큼 놓는다.
                for (k = j; k >= j - L + 1; k--)
                {
                    visit[i][k][0] = 1;
                    tmp[i][k][0] = 1;
                }
            }

            // 진행하는 방향이 1 더 낮다면
            else if (graph[i][j + 1] == graph[i][j] - 1)
            {
                // 경사를 놓을 공간이 "L"보다 부족하면 fail.
                if (N - j < L)
                {
                    possible_route--;
                    break;
                }

                // 경사로가 L 공간만큼 이미 놓여져 있는지 검사
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

                // 경사로가 모두 같은 높이인지 검사
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

                // 경사로를 L 공간만큼 놓는다.
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
            // 높이 차이가 2이상 나면 이 길은 fail
            if (abs(graph[j + 1][i] - graph[j][i]) > 1)
            {
                possible_route--;
                break;
            }
            // 진행하는 방향이 1 더 높다면
            else if (graph[j + 1][i] == graph[j][i] + 1)
            {

                // 경사로를 놓을 공간이 "L" 보다 부족하면 이 길은 fail
                if (j < L)
                {
                    possible_route--;
                    break;
                }

                // 경사로가 L 공간만큼 이미 놓여져 있는지 검사
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

                // 경사로가 모두 같은 높이인지 검사
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

                // 경사로를 L 공간만큼 놓는다.
                for (k = j; k >= j - L + 1; k--)
                {
                    visit[k][i][1] = 1;
                    tmp[k][i][1] = 1;
                }
            }

            // 진행하는 방향이 1 더 낮다면
            else if (graph[j + 1][i] == graph[j][i] - 1)
            {
                // 경사를 놓을 공간이 "L"보다 부족하면 fail.
                if (N - j < L)
                {
                    possible_route--;
                    break;
                }

                // 경사로가 L 공간만큼 이미 놓여져 있는지 검사
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

                // 경사로가 모두 같은 높이인지 검사
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

                // 경사로를 L 공간만큼 놓는다.
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