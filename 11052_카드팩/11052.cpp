#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[1001];
int a[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j, n;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        int p = a[i];
        for (j = i; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - i] + p);
        }
    }

    cout << dp[n] << endl;
    return 0;
}