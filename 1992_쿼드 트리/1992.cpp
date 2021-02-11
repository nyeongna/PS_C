#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

char a[65][65];

void Compress(int x, int y, int n) {
    int i, j, flag=1;
    for(i=x; i<x+n; i++) {
        for(j=y; j<y+n; j++) {
            if (a[x][y] != a[i][j]) flag=0;
        }
    }
    if (flag==1) {
        cout << a[x][y];
        return;
    }
    cout << "(";
    Compress(x, y, n/2);
    Compress(x, y+n/2, n/2);

    Compress(x+n/2, y, n/2);
    Compress(x+n/2, y+n/2, n/2);

    cout << ")";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int i, j, flag=1;

    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cin >> a[i][j];
            if (a[1][1] != a[i][j]) flag=0;
        }
    }
    
    //if (flag==0) cout << "(";
    Compress(1, 1, n);
    //if (flag==0) cout << ")";
    return 0;
}