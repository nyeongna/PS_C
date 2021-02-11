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
            // ��� "��"�� ���ؼ�
            for (i = 1; i <= r_num; i++)
            {
                // ���ڸ� ���� num �迭 �ʱ�ȭ
                // (����, ���ڰ���) �����ϴ� v ���� �ʱ�ȭ
                memset(num, 0, sizeof(num));
                v.clear();

                // �� "��"�� "������ ����"="���� ����"
                for (j = 1; j <= c_num; j++)
                {
                    num[graph[i][j]]++;
                }

                // num�迭�� 0�� �ƴ� ���ڵ��� v�� push (���⼭ 0�� ����)
                for (k = 1; k <= 100; k++)
                {
                    if (num[k] != 0)
                    {
                        v.push_back({k, num[k]});
                    }
                }

                // v ���͸� ����
                sort(v.begin(), v.end());

                //�� ���� 0���� �ʱ�ȭ�Ѵ�.
                for (k = 1; k <= 100; k++)
                {
                    graph[i][k] = 0;
                }

                // idx = 1 �ʱ�ȭ
                // �ش� 'i'���� ���ĵ� ���ڷ� �ٲ۴�.
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
            // ��� "��"�� ���ؼ�
            for (i = 1; i <= c_num; i++)
            {
                // ���ڸ� ���� num �迭 �ʱ�ȭ
                // (����, ���ڰ���) �����ϴ� v ���� �ʱ�ȭ
                memset(num, 0, sizeof(num));
                v.clear();

                // �� "��"�� "������ ����"="���� ����"
                for (j = 1; j <= r_num; j++)
                {
                    num[graph[j][i]]++;
                }

                // num�迭�� 0�� �ƴ� ���ڵ��� v�� push (���⼭ 0�� ����)
                for (k = 1; k <= 100; k++)
                {
                    if (num[k] != 0)
                    {
                        v.push_back({k, num[k]});
                    }
                }

                // v ���͸� ����
                sort(v.begin(), v.end());

                //�� "��"�� 0���� �ʱ�ȭ�Ѵ�.
                for (k = 1; k <= 100; k++)
                {
                    graph[k][i] = 0;
                }

                // idx = 1 �ʱ�ȭ
                // �ش� 'i'���� ���ĵ� ���ڷ� �ٲ۴�.
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
