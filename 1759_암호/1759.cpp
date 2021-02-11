#include <bits/stdc++.h>
using namespace std;

int l, c;
char rec[17];
int ch[2];
vector<char> chars;

void DFS(int s, int level)
{
    int i;
    if (level == l && ch[0]<=0 && ch[1] <=0)
    {
        for (i = 0; i < l; i++)
        {
            cout << rec[i];
        }
        cout << endl;
    }
    else
    {
        for (i = s; i < c; i++)
        {
            rec[level] = chars[i];
            if(chars[i]=='a' || chars[i]=='e' || chars[i]=='i' || chars[i]=='o' || chars[i]=='u') {
                ch[0]--;
            }
            else {
                ch[1]--;
            }
            DFS(i + 1, level + 1);
            if(chars[i]=='a' || chars[i]=='e' || chars[i]=='i' || chars[i]=='o' || chars[i]=='u') {
                ch[0]++;
            }
            else {
                ch[1]++;
            }
        }
    }
}

int main()
{
    cin >> l >> c;
    int i;
    char input;

    for (i = 0; i < c; i++)
    {
        cin >> input;
        chars.push_back(input);
    }
    sort(chars.begin(), chars.end());
    ch[0] = 1;
    ch[1] = 2;
    DFS(0, 0);

    return 0;
}