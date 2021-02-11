#include <bits/stdc++.h>
using namespace std;

int main() {

    int r, c;
    cin >> r >> c;
    getchar();
    int i,j;
    vector<vector<int> > graph(r, vector<int>(c, 0));
    
    for(i=0; i<r; i++) {
        string line;
        getline(cin, line);
        for(j=0; j<c; j++) {
            graph[i][j]=line[j]-'0';
        }
    }
    vector<vector<int> > visited(r, vector<int>(c,0));
    visited[0][0]=1;
    queue<tuple<int,int,int> > Q;
    Q.push({0,0,1});

    int x_dir[4] = {-1,0,1,0};
    int y_dir[4] = {0,1,0,-1};
    while (!Q.empty()) {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int dist = get<2>(Q.front());
        Q.pop();
        if (x==r-1 && y==c-1) {
            cout << dist << endl;
            return 0;
        }
        for(i=0; i<4; i++) {
            int dx = x + x_dir[i];
            int dy = y + y_dir[i];
            if (dx >= 0 && dx < r && dy >=0 && dy < c && visited[dx][dy]==0 && graph[dx][dy]==1) {
                visited[dx][dy]=1;
                Q.push({dx, dy, dist+1});
            }
        }
    }
    return 0;
}