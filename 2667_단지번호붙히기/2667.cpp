#include <bits/stdc++.h>
using namespace std;

int n;
int graph[30][30];
int cnt = 0;
int x_dir[4] = {-1,0,1,0};
int y_dir[4] = {0,1,0,-1};

void DFS(int x, int y) {
    for(int i=0; i<4; i++) {
        int dx = x + x_dir[i];
        int dy = y + y_dir[i];
        if (dx>=1 && dx<=n && dy>=1 && dy<=n && graph[dx][dy]==1) {
            cnt++;
            graph[dx][dy] = 0;
            DFS(dx,dy);
        }
    }
}

int main()
{
    cin >> n;
    int i, j;
    vector<int> house;
    char one_line[30];
    
    for (i = 1; i <= n; i++)
    {
        cin >> one_line;
        for (j = 0; j < strlen(one_line); j++)
        {
            graph[i][j+1] = one_line[j]-48;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cnt=0;
            if (graph[i][j] == 1)
            {
                cnt++;
                graph[i][j]=0;
                DFS(i,j);
                house.push_back(cnt);
            }
        }
    }
    sort(house.begin(), house.end());
    cout << house.size() <<endl;
    for(i=0; i<house.size(); i++) {
        cout << house[i] << endl;
    }

    return 0;
}