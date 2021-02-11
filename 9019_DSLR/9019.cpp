#include <bits/stdc++.h>
using namespace std;

int t;
char a[5];
char b[5];
int aa, bb;

char a2[5];

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

void init_a2()
{
    for (int i = 0; i < 5; i++)
    {
        a2[i] = '0';
    }
    a2[4] = '\0';
}

void change_a(int ans)
{
    int c = 3;
    init_a();
    while (ans != 0)
    {
        int tmp = ans % 10;
        a[c--] = tmp + '0';
        ans = ans / 10;
    }
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

int toInt()
{
    return (a[0]-'0') * 1000 + (a[1]-'0') * 100 + (a[2]-'0') * 10 + (a[3]-'0') * 1;
}

void toChar(int ans) {
    int c = 3;
    init_a2();
    while (ans != 0)
    {
        int tmp = ans % 10;
        a2[c--] = tmp + '0';
        ans = ans / 10;
    }
}

int D()
{
    int input = toInt();
    int ans = (input * 2) % 10000;
    change_a(ans);
    return toInt();
}

void un_D()
{
    int input = toInt();
    int ans = (input / 2) % 10000;
    change_a(ans);
}

int S()
{
    int input = toInt();
    int ans = input - 1;
    if (ans == -1)
    {
        change_a(9999);
    }
    else
    {
        change_a(ans);
    }
    return toInt();
}
void un_S()
{
    int input = toInt();
    int ans = input + 1;
    if (ans == 10000)
    {
        change_a(0);
    }
    else
    {
        change_a(ans);
    }
}
int L()
{
    char zero = a[0];
    a[0] = a[1];
    a[1] = a[2];
    a[2] = a[3];
    a[3] = zero;
    return toInt();
}
int R()
{
    char last = a[3];
    a[3] = a[2];
    a[2] = a[1];
    a[1] = a[0];
    a[0] = last;
    return toInt();
}

int getResult(int a2)
{
    int c = (b[0]-'0') * 1000 + (b[1]-'0') * 100 + (b[2]-'0') * 10 + (b[3]-'0') * 1;
    if (a2 == c)
        return 1;
    else
        return 0;
}

char rec[1000];

int main()
{
    cin >> t;
    int i, j, cnt = 0, output, level;
    queue<pair<int, int>> Q;

    for (i = 1; i <= t; i++)
    {
        output = 0;
        level = 0;
        init();
        getInput();
        cout << a << " " << b << endl;

        Q.push({toInt(), cnt});
        while (!Q.empty())
        {
            output = Q.front().first;
            level = Q.front().second;
            toChar(output);

            Q.pop();

            if (getResult(output) == 1)
            {
                cout << "ccc" << endl;
                for (int i = 0; i < level; i++)
                {
                    cout << rec[i];
                }
                cout << endl;
                break;
            }
            
            rec[cnt] = 'D';
            Q.push({D(), cnt + 1});
            un_D();

            
            rec[cnt] = 'S';
            Q.push({S();, cnt + 1});
            un_D();

            ;
            rec[cnt] = 'L';
            Q.push({L(), cnt + 1});
            R();

            
            rec[cnt] = 'R';
            Q.push({R();, cnt + 1});
            L();
        }
        for (int j = 0; j < level; j++)
        {
            rec[j] = '0';
        }
    }

    return 0;
}