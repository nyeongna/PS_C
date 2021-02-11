#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int a[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int i, j;
    int r=1, c=1, rfirst=1, cfirst=1, rlast=n, clast=n;
    int value = n*n;
    int x, y;
    while (value!=0) {
        a[r][c] = value;
        value--;
        if (a[r][c]==k) {
            x=r, y=c;
        }
        
        if (r < rlast && c==cfirst) {
            r++;
            if (r==rlast) cfirst++;
        }
        else if (c < clast && r==rlast) {
            c++;
            if (c==clast) rlast--;
        }
        else if (r > rfirst && c==clast) {
            r--;
            if (r==rfirst) clast--;
        }
        else if (c > cfirst && r==rfirst) {
            c--;
            if (c==cfirst) rfirst++;
        }
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << x << " " << y << endl;


    return 0;
}