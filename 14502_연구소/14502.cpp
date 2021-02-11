#include <bits/stdc++.h>
using namespace std;

int m, n;
int graph[9][9];
int visit[9][9];
int x_dir[4] = {-1,0,1,0};
int y_dir[4] = {0,1,0,-1};
int ans = -2147000000;
vector<pair<int,int>> vec;

void getInput()
{
    cin >> m >> n;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j]==2) {
                vec.push_back({i,j});
            }
        }
    }
}
void Print() {
    int i, j;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int BloodFill() {
    memset(visit, 0, sizeof(visit));
    queue<pair<int,int>> Q;
    int i, j;
    for(i=0; i<vec.size(); i++) {
        Q.push({vec[i].first, vec[i].second});
        
    }
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(i=0; i< 4; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx>=1 && dx<=m && dy>=1 && dy<=n && graph[dx][dy]==0 && visit[dx][dy]==0) {
                visit[dx][dy] = 1;
                Q.push({dx,dy});
            }
        }
    }
    int safe=0;
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if (graph[i][j]==0 && visit[i][j]==0) {
                safe++;
            }
        }
    }
    return safe;
}

void DFS(int idx, int cnt) {
    if (cnt==3) {
        int safe = BloodFill();
        ans = max(ans, safe);
        return;
    }
    int i, j;
    for(i=idx; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if (graph[i][j]==0) {
                graph[i][j]=1;
                DFS(i, cnt+1);
                graph[i][j]=0;
            }
        }
    }    
}

void Solve() {
    DFS(1, 0);
}
int main()
{
    getInput();
    //Print();
    Solve();
    cout << ans << endl;
    return 0;
}