#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[501][501];
int visit[501][501];
int cnt;

void getInput() {
    cin >> n >> m;
    int i ,j;
    int a, b;
    // dist 초기화
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            dist[i][j] = (i==j ? 0 : 1000000);
        }
    }
    // 친구들 키 관계 받기
    for(i=1; i<=m; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
    }
}
void Print() {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cout << dist[i][j] << "\t";
        }

        cout << endl;
    }
}

void Check(int target) {
    int i, j;
    for(i=1; i <=n; i++) {
        if (dist[target][i]!=1000000) {
            visit[target][i] = 1;
        }
        if (dist[i][target] != 1000000) {
            visit[target][i] = 1;
        }
    }
    for(i=1; i<=n; i++) {
        if (visit[target][i]==0) return;
    }
    cnt++; 
}
void Print2() {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cout << visit[i][j] <<  " ";
        }
        cout << endl;
    }
}
void Solve() {
    int i, j, k;
    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //Print();
    for(i=1; i<=n; i++) {
        Check(i);
    }
    //Print2();
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getInput();
    Solve();

}