#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int
    int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;

    cin >> n;
    int i, j;
    
    for(i=0; i<=1000001; i++) {
        dp[i] = 2147000000;
    }
    dp[1] = 0;
    for(i=1; i<=n; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        if (i*2 <= n) dp[i*2] = min(dp[i*2], dp[i]+1);
        if (i*3 <= n) dp[i*3] = min(dp[i*3], dp[i]+1); 
    }
    cout << dp[n] << endl;
    return 0;
}