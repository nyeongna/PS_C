#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 10007

int n;
int dp[1001][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, j, k;
    for(i=0; i<=9; i++) {
        dp[1][i] = 1;
    }

    for(i=2; i<=n; i++) {
        for(j=0; j<=9; j++) {
            for(k=j; k<=9; k++) {
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= MOD;
            }
        }
    }
    int ans=0;
    for(i=0; i<=9; i++) {
        ans = (ans + dp[n][i])%MOD;
    }
    cout << ans << endl;
    
    return 0;
}