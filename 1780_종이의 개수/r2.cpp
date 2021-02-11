#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[2200][2200];
int cnt[3];
int n;

void Divide(int x, int y, int n) {
    if (n == 1) {
        cnt[a[x][y]+1]++;
        return;
    }
    int i, j, flag=1;
    for(i=x; i<x+n; i++) {
        for(j=y; j<y+n; j++) {
            if (a[x][y] != a[i][j]) flag=0;
        }
    }
    if (flag) {
        cnt[a[x][y]+1]++;
        return;
    }

    Divide(x, y, n/3);
    Divide(x, y+n/3, n/3);
    Divide(x, y+n/3*2, n/3);

    Divide(x+n/3, y, n/3);
    Divide(x+n/3, y+n/3, n/3);
    Divide(x+n/3, y+n/3*2, n/3);

    
    Divide(x+n/3*2, y, n/3);
    Divide(x+n/3*2, y+n/3, n/3);
    Divide(x+n/3*2, y+n/3*2, n/3);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    Divide(1,1,n);
    
    cout << cnt[0] << endl;
    cout << cnt[1] << endl;
    cout << cnt[2] << endl;


    return 0;
}