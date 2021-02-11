#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int rec[21];
int a[21];
int n, s;
int cnt;

void DFS(int level) {
    int i, total=0;
    if (level == n) {
        int flag=0;
        for(i=0; i<n; i++) {
            if (rec[i]==1) flag=1;
        }
        if (flag==0) return;
        
        for(i=0; i<n; i++) {
            if (rec[i]) total = total + a[i];
        }
        if (total==s) {
            cnt++;
        }
        return;
    }
    rec[level]=1;
    DFS(level+1);
    rec[level]=0;
    DFS(level+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j, total = 0;
    cin >> n >> s;
    for(i=0; i<n; i++) {
        cin >> a[i];
    }

    DFS(0);
    cout << cnt << endl;
    return 0;
}