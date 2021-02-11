#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 10007

int n, k;

long long Factorial[1001];
long long dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    int i, j;
    for(i=1; i<=n; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for(i=2; i<=n; i++) {
        for(j=1; j<=k; j++) {
            dp[i][j] = (dp[i-1][j-1]%MOD + dp[i-1][j]%MOD)%MOD;
        }
    }
    cout << dp[n][k] << endl;
    
    return 0;
}