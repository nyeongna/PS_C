#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

long long int dp[91][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, i;
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
    }
    cout << dp[n][0] + dp[n][1] << endl;


    

    return 0;
}