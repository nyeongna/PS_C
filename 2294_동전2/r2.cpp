#include <bits/stdc++.h>
using namespace std;

int coins[101];
int dp[10001];

int main() {
    int n, k;
    cin >> n >> k;
    int i, val, j;
    for(i=1; i<=k; i++) {
        dp[i]=2147000000;
    }
    for(i=0; i<n; i++) {
        cin >> val;
        for(j=val; j<=k; j++) {
            dp[j] = min(dp[j-val]+1, dp[j]);
        }
    }
    if (dp[k]==2147000000) {
        cout << -1 << endl;
    }
    else {
        cout << dp[k] << endl;
    }
    
    return 0;
}