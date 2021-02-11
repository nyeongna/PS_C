#include <bits/stdc++.h>
using namespace std;

int t;
char a[5];
char b[5];
int aa, bb;

void init()
{
    for (int i = 0; i < 5; i++)
    {
        a[i] = '0';
        b[i] = '0';
    }
    a[4] = '\0';
    b[4] = '\0';
}

void init_a()
{
    for (int i = 0; i < 5; i++)
    {
        a[i] = '0';
    }
    a[4] = '\0';
}

int toInt()
{
    return (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0') * 1;
}

int change_a(int ans)
{
    int c = 3;
    init_a();
    while (ans != 0)
    {
        int tmp = ans % 10;
        a[c--] = tmp + '0';
        ans = ans / 10;
    }
    return toInt();
}

void getInput()
{
    int c = 3;
    cin >> aa >> bb;
    while (aa != 0)
    {
        int tmp = aa % 10;
        a[c--] = tmp + '0';
        aa = aa / 10;
    }
    c = 3;
    while (bb != 0)
    {
        int tmp = bb % 10;
        b[c--] = tmp + '0';
        bb = bb / 10;
    }
}

int D(int input)
{
    change_a((input * 2) % 10000);
    return toInt();
}

int S(int input)
{
    int s_input = input - 1;
    if (s_input == -1)
    {
        change_a(9999);
    }
    else
    {
        change_a(s_input);
    }
    return toInt();
}

int L(int input)
{
    change_a(input);
    char zero = a[0];
    a[0] = a[1];
    a[1] = a[2];
    a[2] = a[3];
    a[3] = zero;
    return toInt();
}

int R(int input)
{
    change_a(input);
    char last = a[3];
    a[3] = a[2];
    a[2] = a[1];
    a[1] = a[0];
    a[0] = last;
    return toInt();
}

int getResult(int input)
{
    int c = (b[0] - '0') * 1000 + (b[1] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0') * 1;
    if (input == c)
        return 1;
    else
        return 0;
}

int visit[10001];

void clear(std::queue<pair<int, string>> &q)
{
    std::queue<pair<int, string>> empty;
    std::swap(q, empty);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int i, j, cnt = 0, output, level;
    queue<pair<int, string>> Q;

    for (i = 1; i <= t; i++)
    {
        init();
        getInput();
        //cout << a << " " << b << endl;

        Q.push({toInt(), ""});
        visit[toInt()] = 1;

        while (!Q.empty())
        {
            int now = Q.front().first;
            string path = Q.front().second;

            Q.pop();

            //cout << "now: " << now << " " << "path: " << path << endl;

            if (getResult(now) == 1)
            {
                cout << path << endl;
                break;
            }
            //rec[level] = 'D';
            if (visit[D(now)] == 0)
            {
                visit[now] = 1;
                Q.push({D(now), path + "D"});
            }

            //rec[level] = 'S';
            if (visit[S(now)] == 0)
            {
                visit[now] = 1;
                Q.push({S(now), path + "S"});
            }

            if (visit[L(now)] == 0)
            {
                visit[now] = 1;
                Q.push({L(now), path + "L"});
            }

            if (visit[R(now)] == 0)
            {
                visit[now] = 1;
                Q.push({R(now), path + "R"});
            }
        }
        clear(Q);
        memset(visit, 0, sizeof(visit));
    }
}