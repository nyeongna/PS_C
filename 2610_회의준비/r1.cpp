#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[101][101];
int check[101];
int rec[101];
int rev[101];

void getInput() {
    cin >> n >> m;
    int i, j;
    for(i=1; i<=n; i++) {
        rec[i] = 1000000;
        check[i] = i;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            dist[i][j] = dist[j][i] = (i == j ? 0 : 1000000);
        }
    }
    int from, to;
    for (i = 1; i <= m; i++) {
        cin >> from >> to;
        dist[from][to] = dist[to][from] = 1;
    }
}
void Print() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
int Find(int a) {
    if (check[a] == a) return a;
    return check[a] = Find(check[a]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) check[a] = b;
}
void Solve() {
    int i, j, k;

    // 플로이드 와샬
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Union-Find 합치기
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dist[i][j] != 1000000) Union(i, j);
        }
    }

    for (i = 1; i <= n; i++) {
        int max_num = -10;
        for (j = 1; j <= n; j++) {
            if (dist[i][j] == 1000000) continue;
            max_num = max(max_num, dist[i][j]);
            //cout << max_num << endl;
        }
        if (max_num == -10) continue;
        //cout << max_num << " " << rec[Find(i)] << endl;
        if (max_num < rec[Find(i)]) {
            rec[Find(i)] = max_num;
            rev[Find(i)] = i;
        }
    }

    vector<int> leader;
    for(i=1; i<=n; i++) {
        if (rev[i]!=0) leader.push_back(rev[i]);
    }
    sort(leader.begin(), leader.end());
    cout << leader.size() << endl;
    for(i=0; i<leader.size(); i++) {
        cout << leader[i] << endl;
    }
    //Print();
}
int main() {
    getInput();
    Solve();
    return 0;
}