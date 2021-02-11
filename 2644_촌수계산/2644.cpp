#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    int i, j;
    int m;
    int p, c;
    cin >> n;
    cin >> x >> y;
    cin >> m;
    vector<int> graph[101];
    for(i=0; i<m; i++) {
        cin >> p >> c;
        graph[p].push_back(c);
        graph[c].push_back(p);
    }
    queue<pair<int, int> > Q;
    Q.push({x, 0});
    vector<int> visited(101, 0);
    visited[x]=1;

    while (!Q.empty()) {
        int output = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        if (output==y) {
            cout << dist << endl;
            return 0;
        }
        for(i=0; i<graph[output].size(); i++) {
            int next = graph[output][i];
            if (visited[next]==0) {
                visited[next]=1;
                Q.push({next, dist+1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}