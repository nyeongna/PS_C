#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
int cnt;
int r_num = 3;
int c_num = 3;
int graph[101][101];

void getInput()
{
    cin >> r >> c >> ans;
    int i, j;

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            cin >> graph[i][j];
        }
    }
}
typedef struct State
{
    int x;
    int num;

    bool operator<(const State &b) const
    {
        if (num == b.num)
        {
            return x < b.x;
        }
        return num < b.num;
    }
} State;

void Print()
{
    int i, j;

    for (i = 1; i <= r_num; i++)
    {
        for (j = 1; j <= c_num; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl <<endl;
    }
    
}

void Solve()
{
    int i, j, k, idx = 1, size=0;
    int num[101];
    vector<State> v;

    while (1)
    {
        if (cnt > 100)  {
            cout << -1 << endl;
            return;
        }

        if (graph[r][c] == ans)
        {
            //cout <<graph[r][c] << " "<< k << endl;
            cout << cnt << endl;
            return;
        }

        // R Operation
        if (r_num >= c_num)
        {
            cnt++;
            // 모든 "행"에 대해서
            for (i = 1; i <= r_num; i++)
            {
                // 숫자를 세는 num 배열 초기화
                // (숫자, 숫자갯수) 저장하는 v 벡터 초기화
                memset(num, 0, sizeof(num));
                v.clear();

                // 각 "행"당 "원소의 갯수"="열의 갯수"
                for (j = 1; j <= c_num; j++)
                {
                    num[graph[i][j]]++;
                }

                // num배열에 0이 아닌 숫자들을 v에 push (여기서 0은 제외)
                for (k = 1; k <= 100; k++)
                {
                    if (num[k] != 0)
                    {
                        v.push_back({k, num[k]});
                    }
                }

                // v 벡터를 정렬
                sort(v.begin(), v.end());

                //각 행을 0으로 초기화한다.
                for (k = 1; k <= 100; k++)
                {
                    graph[i][k] = 0;
                }

                // idx = 1 초기화
                // 해당 'i'행을 정렬된 숫자로 바꾼다.
                idx = 1;
                int v_size = v.size();
                size = min(50, v_size);
                for (k = 0; k < size; k++)
                {

                    graph[i][idx++] = v[k].x;
                    graph[i][idx++] = v[k].num;
                }
                c_num = max(c_num, size*2);
            }

        }

        else
        {
            cnt++;
            // 모든 "행"에 대해서
            for (i = 1; i <= c_num; i++)
            {
                // 숫자를 세는 num 배열 초기화
                // (숫자, 숫자갯수) 저장하는 v 벡터 초기화
                memset(num, 0, sizeof(num));
                v.clear();

                // 각 "열"당 "원소의 갯수"="행의 갯수"
                for (j = 1; j <= r_num; j++)
                {
                    num[graph[j][i]]++;
                }

                // num배열에 0이 아닌 숫자들을 v에 push (여기서 0은 제외)
                for (k = 1; k <= 100; k++)
                {
                    if (num[k] != 0)
                    {
                        v.push_back({k, num[k]});
                    }
                }

                // v 벡터를 정렬
                sort(v.begin(), v.end());

                //각 "열"을 0으로 초기화한다.
                for (k = 1; k <= 100; k++)
                {
                    graph[k][i] = 0;
                }

                // idx = 1 초기화
                // 해당 'i'열을 정렬된 숫자로 바꾼다.
                idx = 1;
                int v_size = v.size();
                size = min(50, v_size);
                for (k = 0; k < size; k++)
                {
                    graph[idx++][i] = v[k].x;
                    graph[idx++][i] = v[k].num;
                }
                r_num = max(r_num, 2 * size);
            }
        }
    }
}
int main()
{
    getInput();
    Solve();

    return 0;
}
