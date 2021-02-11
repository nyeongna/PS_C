#include<bits/stdc++.h>
using namespace std;

int n, m;
int dist[101][101];
int relation[101];

int Find(int x) {
    if (relation[x] == x) 
        return x;
    else 
        return relation[x] = Find(relation[x]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a!=b) {
        relation[a] = b;
    }
}

void Relation() {
    int i, j;
    for(i=1; i<=n; i++) {
        relation[i] = i;
    }
}

void getInput() {
    cin >> n >> m;
    int i, j, from, to;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if (i==j) dist[i][j]=0;
            else dist[i][j]=1000000;
        }
    }
    Relation();

    for(i=1; i<=m; i++) {
        cin >> from >> to;
        dist[from][to]=1;
        dist[to][from]=1;
        Union(from,to);
    }

    // for(i=1; i<=n; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(i=1; i<=n; i++) {
    //     cout << relation[i] << " ";
    // }
}

void Solve() {
    int i, j, k;
    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if (i==j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //cout << endl;
    // for(i=1; i<=n; i++) {
    //     for(j=1; j<=n; j++) {
    //         cout << dist[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    vector<pair<int,int>> a[n+1];
    int max_num = -2147000000;

    for(i=1; i<=n; i++) {
        max_num = -2147000000;
        for(j=1; j<=n; j++) {
            if (dist[i][j]!=1000000) max_num = max(max_num, dist[i][j]);
        }
        a[Find(i)].push_back({max_num, i});
    }

    int cnt=0;
    for(i=1; i<=n; i++) {
        if (relation[i]==i) cnt++;
    }
    for(i=1; i<=n; i++) {
        if (a[i].size() != 0) {
            sort(a[i].begin(), a[i].end());
        }
    }
    //cout << cnt << endl;

    vector<int> b;
    for(i=1; i<=n; i++) {
        if (a[i].size() !=0) {
            b.push_back(a[i].front().second);
            //cout << a[i].front().second << endl;
            // for(j=0; j<a[i].size(); j++) {
            //     cout << a[i][j].first << " " << a[i][j].second<< "  ";
            // }
            // cout << endl;
        }
    }
    sort(b.begin(), b.end());
    cout << b.size() << endl;
    for(i=0; i<b.size(); i++) {
        cout << b[i] << endl;
    }

}
int main() {
    getInput();
    Solve();
    return 0;
}