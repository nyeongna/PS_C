#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int a[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k, i, j;
    cin >> n >> k;

    int r = 1, c = 1;
    int value = pow(n, 2);
    //cout << value << endl;

    int rfirst = 1, rlast = n, cfirst = 1, clast = n;
    int ans1, ans2;

    while (value != 0) {
        a[r][c] = value;
        if (a[r][c]==k) {
            ans1=r, ans2 =c;
        }
        value--;
        if (r < rlast && c == cfirst) {
            r++;
            if (r == rlast) cfirst++;
        }
        else if (r == rlast && c < clast) {
            c++;
            if (c == clast) rlast--;
        }
        else if (c == clast && r > rfirst) {
            r--;
            if (r == rfirst) clast--;
        }
        else if (r == rfirst && c > cfirst) {
            c--;
            if (c == cfirst) rfirst++;
        }
        // cout << endl;
        // for (i = 1; i <= n; i++) {
        //     for (j = 1; j <= n; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << r << " " << c << " " << rfirst << " " << rlast << " " << cfirst << " " << clast << endl << endl;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans1 << " " << ans2 << endl;

    return 0;
}