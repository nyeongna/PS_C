#include <bits/stdc++.h>
using namespace std;

/*
    https://jaimemin.tistory.com/584
    
    지나온 곳을 출력하는 Print() 함수가 관건!

*/

int n, k;
int visit[100001];
int path[100001];

void getInput()
{
    cin >> n >> k;
}

typedef struct State
{
    int cur;
    int dist;
} State;

// 이전 방문노드를 타고타고 올라가는 방법.
void Print()
{
    vector<int> vec;
    while (k != n)
    {
        vec.push_back(k);
        k = path[k];
    }
    vec.push_back(n);
    int i;
    for (i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i] << " ";
    }
}

void BFS()
{
    queue<State> Q;
    Q.push({n, 0});
    visit[n] = 1;
    path[n] = n;

    while (!Q.empty())
    {
        int cur = Q.front().cur;
        int dist = Q.front().dist;
        Q.pop();

        if (cur == k)
        {
            cout << dist << endl;

            // 핵심 함수!
            // 이전 방문노드를 계속 타고 올라간다.
            Print();
            exit(0);
        }

        if (cur + 1 <= 100000 && visit[cur + 1] == 0)
        {
            visit[cur + 1] = 1;
            path[cur + 1] = cur;
            Q.push({cur + 1, dist + 1});
        }
        if (cur - 1 >= 0 && visit[cur - 1] == 0)
        {
            visit[cur - 1] = 1;
            path[cur - 1] = cur;
            Q.push({cur - 1, dist + 1});
        }
        if (cur * 2 <= 100000 && visit[cur * 2] == 0)
        {
            visit[cur * 2] = 1;
            path[cur * 2] = cur;
            Q.push({cur * 2, dist + 1});
        }
    }
}

int main()
{
    getInput();
    BFS();
    return 0;
}